/*
 * BranchStatement.hpp
 *
 *  Created on: Nov 28, 2017
 *      Author: naopross
 */

#ifndef SRC_DIAGRAM_BRANCHSTATEMENT_HPP_
#define SRC_DIAGRAM_BRANCHSTATEMENT_HPP_

#include "Statement.hpp"

#include <map>

namespace samb {

class BranchStatement: public Statement {
public:
    BranchStatement(Type t, const std::string& condition, pointer next);

    /* accessors */
    const std::map<std::string, pointer>& branches() const { return m_branches; }
    std::size_t branchesCount() const { return m_branchesCount; }

    inline const std::string& condition() const { return text(); }
    inline void condition(const std::string& condition) { return text(condition); }

private:
    std::map<std::string, pointer> m_branches;
    std::size_t m_branchesCount = 0;
};

} /* namespace samb */

#endif /* SRC_DIAGRAM_BRANCHSTATEMENT_HPP_ */
