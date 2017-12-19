#ifndef DIAGRAM_SCOPE_H
#define DIAGRAM_SCOPE_H

#include "diagram/statement.h"

#include <QString>

namespace samb {

/* The Scope is a forward-iterable object that contains statements.
 * A scope is also a valid type of statement.
 *
 * The Scope object is used inside other complex types of statements such as
 * BranchStatement or a IteratorStatement, to hold the statements within their
 * scope.
 */
class Scope : public Statement
{
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
        Statement::pointer _current;
    };

    explicit Scope(const QString &label);
    Scope(const QString &label, Statement::pointer first);
    virtual ~Scope();

    iterator insert_after(iterator it, Statement::pointer statement);
    iterator erase_after(iterator it);

    /* accessors */
    std::size_t size() const { return _size; }

    /* iterator */
    iterator begin() { return iterator(_head); }
    iterator end() { return iterator(_tail); }

private:
    Statement::pointer _head;
    Statement::pointer _tail;
    std::size_t _size = 0;
};

} /* namespace samb */

#endif /* SRC_DIAGRAM_SCOPE_HPP_ */
