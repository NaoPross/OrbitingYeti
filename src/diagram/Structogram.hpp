/*
 * Structogram.h
 *
 *  Created on: Nov 14, 2017
 *      Author: naopross
 */

#ifndef STRUCTOGRAM_H_
#define STRUCTOGRAM_H_

#include <iostream>
#include <list>

#include "Statement.hpp"

namespace samb {

/* A Structogram is a Nassi-Schneiderman diagram, in this implementation it is
 * simply and iterable object that holds statements.
 *
 * The first statement inside a structogram (m_head) is a SCOPE
 * statement that holds the entire program inside it.
 */
class Structogram {
public:
	/* forward only iterator */
	class iterator {
	public:
		iterator(Statement::pointer first);
		~iterator();

		iterator& operator++();
		iterator& operator++(int);

		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;
		Statement& operator*() const;
		Statement::pointer operator->() const;

	private:
		Statement::pointer m_current;
	};

	Structogram(std::string title);
	virtual ~Structogram();

	std::size_t size() const;

	// cannot be implemented because iter is forward only
//	iterator insert(iterator it, Statement::pointer statement);
//	iterator erase(iterator it);

	iterator insert_after(iterator it, Statement::pointer statement);
	iterator erase_after(iterator it);

	/* iterator */
	iterator begin() const;
	const iterator end() const;
	const Statement& operator[](const Statement& it) = delete;

private:
	std::size_t m_size;
	std::string m_title;

	Statement::pointer m_head;
	Statement::pointer m_tail;
};

} /* namespace structograms */

#endif /* STRUCTOGRAM_H_ */
