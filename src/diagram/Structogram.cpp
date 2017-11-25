/*
 * Structogram.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: naopross
 */

#include "../diagram/Structogram.h"
#include <memory>


namespace samb {

Structogram::Structogram(std::string title): m_title(title) {

}

Structogram::~Structogram() {

}

const std::list<Statement>& Structogram::getStatements() const {
	return m_statements;
}


} /* namespace structograms */
