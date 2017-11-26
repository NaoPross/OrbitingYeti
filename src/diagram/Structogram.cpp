/*
 * Structogram.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: naopross
 */

#include "../diagram/Structogram.hpp"
#include <memory>
#include <exception>


namespace samb {

/* iterator nested class */
Structogram::iterator::iterator(Statement::pointer first) {
	m_current = first;
}

Structogram::iterator::~iterator() {}

Structogram::iterator& Structogram::iterator::operator++() {
	if (m_current->next != nullptr) {
		m_current = m_current->next;
	}

	return *this;
}

Structogram::iterator& Structogram::iterator::operator++(int) {
	static iterator old(*this);
	old = *this;

	operator++();
	return old;
}

bool Structogram::iterator::operator==(const iterator& other) const {
	if (*this->m_current == *other.m_current) {
		return true;
	}

	return false;
}

bool Structogram::iterator::operator!=(const iterator& other) const {
	return !(other == *this);
}

Statement& Structogram::iterator::operator*() const {
	if (m_current == nullptr) {
		throw std::logic_error("structogram iterator: m_current is nullptr");
	}

	return *m_current;
}

Statement::pointer Structogram::iterator::operator->() const {
	return m_current;
}


/**
 *  Structogram class methods
 */
Structogram::Structogram(std::string title) {

	m_size = 0;
	m_title = title;

	m_head = Statement::makeStatement(Statement::Type::SCOPE);
	m_tail = Statement::makeStatement(Statement::Type::END);

	m_head->next = m_tail;
	m_head->text = m_title;
}

Structogram::~Structogram() {
	/* no need to destroy anything because of smart pointers */
}

std::size_t Structogram::size() const {
	return m_size;
}

Structogram::iterator Structogram::insert_after(Structogram::iterator it, Statement::pointer statement) {

	if (statement == nullptr) {
		throw std::invalid_argument("structogram: attempt to insert a null statement");
	}

	statement->next = it->next;
	it->next = statement;
	m_size++;

	return ++it;
}

//Structogram::iterator Structogram::insert_after(Structogram::iterator it, Statement::pointer statement) {
//	return insert(++it, statement);
//}

Structogram::iterator Structogram::erase_after(iterator it) {

	// TODO: error handling IE return a std::pair<iterator, bool>

	/* the first statement (scope of the program) cannot be deleted */
	if ((*it) == *m_head) {
		return it;
	}

	if (it->next == nullptr) {
		return it;
	}

	it->next = it->next->next;

	return it;
}

/* iterator related methods */
Structogram::iterator Structogram::begin() const {
	return iterator(m_head);
}

const Structogram::iterator Structogram::end() const {
	return iterator(m_tail);
}

} /* namespace structograms */
