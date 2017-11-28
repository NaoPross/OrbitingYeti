/*
 * BranchStatement.hpp
 *
 *  Created on: Nov 28, 2017
 *      Author: naopross
 */

#ifndef SRC_DIAGRAM_BRANCHSTATEMENT_HPP_
#define SRC_DIAGRAM_BRANCHSTATEMENT_HPP_

#include "Statement.hpp"

namespace samb {

class BranchStatement: public Statement {
public:
	BranchStatement(Type t, const std::string& condition, pointer next);

	const std::string& condition() const { return text(); }
	void condition(const std::string& condition) { return text(condition); }

	std::vector<std::string> branches();
	std::size_t branchesCount();

private:
	std::map<std::string, pointer> m_branches;
	std::size_t m_branchesCount = 0;
};

} /* namespace samb */

#endif /* SRC_DIAGRAM_BRANCHSTATEMENT_HPP_ */
