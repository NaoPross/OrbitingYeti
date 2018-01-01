#ifndef DIAGRAM_BRANCHSTATEMENT_H
#define DIAGRAM_BRANCHSTATEMENT_H

#include "diagram/statement.h"

#include <map>
#include <QString>

namespace samb {

/* Implementation for Statement::DECISION, Statement::SWITCH
 */
class Branch : public Statement
{
public:
    Branch(Type t, const QString &condition, pointer next);

    /* accessors */
    std::map<QString, pointer>& branches() { return _branches; }
    std::size_t branchesCount() const { return _branchesCount; }

    inline const QString& condition() const { return text(); }
    inline void condition(const QString &condition) { return text(condition); }

private:
    std::map<QString, pointer> _branches;
    std::size_t _branchesCount = 0;
};

} /* namespace samb */

#endif /* DIAGRAM_BRANCHSTATEMENT_H */
