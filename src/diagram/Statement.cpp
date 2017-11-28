/*
 * Statement.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: naopross
 */

#include "Statement.hpp"

namespace samb {

/* Statement */
Statement::Statement(Type t, const std::string& text, Statement::pointer p): type(t), m_text(text), m_next(p) {}

Statement::~Statement() {}

bool Statement::operator==(const Statement& other) const {
	// comparison by pointers
	return (this == &other);
}

} /* namespace samb */
