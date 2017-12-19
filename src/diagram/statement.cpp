#include "diagram/statement.h"

using namespace samb;

/* Statement */

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

bool Statement::operator==(const Statement& other) const {
    // comparison by pointers
    return (this == &other);
}

