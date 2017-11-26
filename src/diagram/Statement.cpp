/*
 * Statement.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: naopross
 */

#include "Statement.hpp"

namespace samb {

Statement::pointer Statement::makeStatement(Statement::Type t) {
	return std::make_shared<Statement>(Statement(t, "", nullptr, nullptr));
}

bool Statement::operator==(const Statement& other) {
	return (this->type == other.type) && (this->text == other.text) &&
			(this->next == other.next) && (this->scope == other.scope);
}


Statement::Statement(Type t, std::string txt, Statement::pointer p, Statement::pointer s): type(t), text(txt), next(p), scope(s) {}
Statement::~Statement() {}

} /* namespace samb */
