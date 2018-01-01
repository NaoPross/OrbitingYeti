#include "diagram/statement.h"

#include "diagram/branch.h"
#include "diagram/iterator.h"
#include "diagram/scope.h"

#include "debugtools.h"

using namespace samb;

/* Statement */

template<class... Args>
static Statement::pointer make(Statement::Type t, Args&& ...args)
{
    Statement::pointer stat;

    switch (t) {
    case Statement::Type::PROCESS:
        stat = new Statement(t, args...);
        break;

    case Statement::Type::DECISION:
    case Statement::Type::PARALLEL:
    case Statement::Type::SWITCH:
        stat = new Branch(t, args...);
        break;

    case Statement::Type::WHILE:
    case Statement::Type::UNTIL:
        stat = new Iterator(t, args...);
        break;

    case Statement::Type::SCOPE:
        stat = new Scope(t, args...);
        break;

    default:
        debug_err("invalid type");
        break;
    }

    return stat;
}

Statement::Statement(Type t, const QString &text) :
    type(t), _text(text), _next(nullptr)
{

}

Statement::Statement(Type t, const QString &text, Statement::pointer p) :
    type(t), _text(text), _next(p)
{

}

Statement::~Statement()
{

}

bool Statement::operator==(const Statement &other) const {
    // comparison by pointers
    return (this == &other);
}

