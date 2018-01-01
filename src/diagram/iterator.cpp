#include "diagram/iterator.h"

using namespace samb;

Iterator::Iterator(Statement::Type t, const QString &condition, Statement::pointer next) :
    Statement(t, condition, next),
    _inner("")
{

    switch (t) {
    case Statement::Type::WHILE:
    case Statement::Type::UNTIL:
        break;

    default:
        throw std::invalid_argument("IteratorStatement can only be of type WHILE or UNTIL");
    }
}
