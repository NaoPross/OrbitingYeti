/*
 *  Created on: Nov 28, 2017
 *      Author: naopross
 */

#ifndef SRC_DIAGRAM_SCOPE_HPP_
#define SRC_DIAGRAM_SCOPE_HPP_

#include "Statement.hpp"

namespace samb {

/* The Scope is a forward-iterable object that contains statements.
 * A scope is also a valid type of statement.
 *
 * The Scope object is used inside other complex types of statements such as
 * BranchStatement or a IteratorStatement, to hold the statements within their
 * scope.
 */
class Scope : public Statement {
public:
    class iterator {
    public:
        explicit iterator(pointer statement);
        ~iterator();

        iterator& operator++();
        iterator& operator++(int);

        Statement& operator*() const;
        Statement::pointer operator->() const;

    private:
        Statement::pointer m_current;
    };

    explicit Scope(std::string label);
    Scope(std::string label, Statement::pointer first);
    ~Scope();

    iterator insert_after(iterator it, Statement::pointer statement);
    iterator erase_after(iterator it);

    /* accessors */
    std::size_t size() const { return m_size; }

    /* iterator */
    iterator begin() { return iterator(m_head); }
    iterator end() { return iterator(m_tail); }

private:
    Statement::pointer m_head;
    Statement::pointer m_tail;
    std::size_t m_size = 0;
};

} /* namespace samb */

#endif /* SRC_DIAGRAM_SCOPE_HPP_ */
