/*
 * Structogram.h
 *
 *  Created on: Nov 14, 2017
 *      Author: naopross
 */

#ifndef STRUCTOGRAM_H_
#define STRUCTOGRAM_H_

#include <iostream>
#include <list>
#include "../diagram/Statement.h"

namespace samb {

/* object that holds statements */
class Structogram {
private:
	std::list<Statement> m_statements;
	std::string m_title;

public:
	Structogram(std::string title);
	virtual ~Structogram();

	const std::list<Statement>& getStatements() const;
};

} /* namespace structograms */

#endif /* STRUCTOGRAM_H_ */
