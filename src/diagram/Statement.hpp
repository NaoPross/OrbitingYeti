/*
 * Statement.h
 *
 *  Created on: Nov 23, 2017
 *      Author: naopross
 */

#ifndef SRC_STATEMENT_H_
#define SRC_STATEMENT_H_

#include <string>

namespace samb {


/*  Possible types of statement, according to the NS diagram paper
 * 
 * PROCESS,
 * DECISION,
 * SWITCH,
 * WHILE,
 * UNTIL,
 * SCOPE,
 * PARALLEL,
 */

/* this class should behave like a std::list,  or a std::map storing the data
 * with a tree structure, BUT it is not a tree because allows 2 notes to point
 * at a single node
 *
 * Normal Tree:          Statements:
 * A - B - C - D         A - B - C - D - G
 *     \                     \      /
 *      E - F                 E - F
 *
 * Because a statement contains branching elmeents. (if / switch)
 */
class Statement {
private:
	Statement *next;
	Statement *prev;

public:
	const enum Type {
		PROCESS,
		DECISION,
		SWITCH,
		WHILE,
		UNTIL,
		SCOPE,
		PARALLEL,
	} m_type;

	Statement(Type type, Statement *prev): m_type(type), m_prev(prev);
	virtual ~Statement();
};

} /* namespace samb */

#endif /* SRC_STATEMENT_H_ */
