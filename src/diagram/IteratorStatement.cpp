/*
 * IteratorStatement.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: naopross
 */

#include "IteratorStatement.hpp"

namespace samb {

IteratorStatement::IteratorStatement(Statement::Type t, const std::string& condition, Statement::pointer next)
	: Statement(t, condition, next), m_inner("") {

	switch (t) {
	case Statement::Type::WHILE:
	case Statement::Type::UNTIL:
		break;

	default:
		throw std::invalid_argument("IteratorStatement can only be of type WHILE or UNTIL");
	}
}

} /* namespace samb */
