#ifndef DIAGRAM_ITERATORSTATEMENT_H
#define DIAGRAM_ITERATORSTATEMENT_H

#include "diagram/statement.h"
#include "diagram/scope.h"

#include <QString>

namespace samb {

/* Implementation for Statement::WHILE Statement::UNTIL
 */
class Iterator : public Statement
{
public:
    Iterator(Type t, const QString &condition, pointer next);

    /* accessors */
    Scope& inner() { return _inner; }

    inline const QString& condition() const { return text(); }
    inline void condition(const QString &condition) { return text(condition); }

private:
    Scope _inner;
};

} /* namespace samb */

#endif /* DIAGRAM_ITERATORSTATEMENT_H */
