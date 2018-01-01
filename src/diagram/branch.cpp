#include "diagram/branch.h"

using namespace samb;

Branch::Branch(Type t, const QString &condition, pointer next) :
    Statement(t, condition, next)
{
    switch (t) {
    case Statement::Type::DECISION:
    case Statement::Type::SWITCH:
        break;

    default:
        throw std::invalid_argument("BranchStatement can only be of type DECISION or SWITCH");
    }
}
