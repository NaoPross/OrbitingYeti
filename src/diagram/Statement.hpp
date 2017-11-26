/*
 * Statement.h
 *
 *  Created on: Nov 23, 2017
 *      Author: naopross
 */

#ifndef SRC_STATEMENT_H_
#define SRC_STATEMENT_H_

#include <string>
#include <memory>

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

/* this struct is a link for linked list that stores the data in a tree-like
 * structure, BUT it is not a tree because it allows 2 or more nodes to point
 * at a single node
 *
 * Tree:                 Statements:
 * A - B - C - D         A - B - C - D - G
 *     \                     \      /
 *      E - F                 E - F
 *
 * Because a statements can be branching elements. (if / switch)
 *
 * This class is also a *Factory* to make statements.
 */
struct Statement {
	using pointer = std::shared_ptr<Statement>;

	enum Type {
		PROCESS,
		DECISION,
		SWITCH,
		WHILE,
		UNTIL,
		SCOPE,
		PARALLEL,

		/* this type of statement indicates the end of the program
		 * and it is used only internally
		 *
		 * TODO: think of something more elegant to solve this
		 */
		END
	} type;

	std::string text;

	pointer next;
	pointer scope; // TODO: make iterator look for this

	static Statement::pointer makeStatement(Type t);
//	static Statement::pointer makeProcess();
//	static Statement::pointer makeLoop(Type t, std::string condition);
//	static Statement::pointer makeBranching(Type t, std::string condition);

	virtual ~Statement();
	bool operator==(const Statement& other);

private:
	Statement(Type type, std::string txt, pointer next, pointer scope);
};

} /* namespace samb */

#endif /* SRC_STATEMENT_H_ */
