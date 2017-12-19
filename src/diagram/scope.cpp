#include "diagram/scope.h"

using namespace samb;

/* Scope::iterator */

Scope::iterator::iterator(Statement::pointer statement) :
    _current(statement)
{

}

Scope::iterator::~iterator()
{

}

Scope::iterator& Scope::iterator::operator++()
{
    if (_current->next() == nullptr) {
        // TODO: remove throw
        throw std::logic_error("Statement::iterator::operator++() m_current->next() is nullptr");
    }

    _current = _current->next();

    return *this;
}

Scope::iterator& Scope::iterator::operator++(int)
{
    static Scope::iterator old(*this);

    old = *this;
    operator++();
    return old;
}

Statement& Scope::iterator::operator*() const
{
    if (_current == nullptr)
        throw std::logic_error("Statement::iterator::operator*() m_current is nullptr");

    return *_current;
}

Statement::pointer Scope::iterator::operator->() const
{
    return _current;
}


/* Scope */

Scope::Scope(const QString &label) :
    Statement(Statement::Type::SCOPE, label, nullptr),
    _head(nullptr), _tail(nullptr)
{

}

Scope::Scope(const QString &label, Statement::pointer first) :
    Statement(Statement::Type::SCOPE, label, first),
    _head(first), _tail(first)
{

}

Scope::~Scope() {

}

Scope::iterator Scope::insert_after(Scope::iterator it, Statement::pointer statement)
{
    if (statement == nullptr)
        throw std::invalid_argument("Statement::insert_after() cannot insert nullptr");

    statement->next(it->next());
    it->next(statement);

    _size++;

    return it;
}

Scope::iterator Scope::erase_after(Scope::iterator it)
{
    if (it->next() == nullptr)
        return end();

    it->next(it->next()->next());

    return it;
}
