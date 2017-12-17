/*
 * IteratorStatement.hpp
 *
 *  Created on: Nov 28, 2017
 *      Author: naopross
 */

#ifndef SRC_DIAGRAM_ITERATORSTATEMENT_HPP_
#define SRC_DIAGRAM_ITERATORSTATEMENT_HPP_

#include "Statement.hpp"
#include "Scope.hpp"

namespace samb {

class IteratorStatement: public Statement {
public:
    IteratorStatement(Type t, const std::string& condition, pointer next);

    /* accessors */
    const Scope& inner() const { return m_inner; }

    inline const std::string& condition() const { return text(); }
    inline void condition(const std::string& condition) { return text(condition); }

private:
    Scope m_inner;
};

} /* namespace samb */

#endif /* SRC_DIAGRAM_ITERATORSTATEMENT_HPP_ */
