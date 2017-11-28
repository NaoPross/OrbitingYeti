/*
 * Statement.h
 *
 *  Created on: Nov 23, 2017
 *      Author: naopross
 */

#ifndef SRC_DIAGRAM_STATEMENT_H_
#define SRC_DIAGRAM_STATEMENT_H_

#include <string>
#include <memory>
#include <vector>
#include <map>

namespace samb {

/*  Possible types of statement, according to the NS diagram paper
 * 
 * PROCESS  : a statement that does something
 * DECISION : splits the program in 2 branches based on a condition
 * SWITCH   : splits the program in n branches depending on a value
 * WHILE    : repeat first loop
 * UNTIL    : repeat last loop
 * SCOPE    : simple scope to isolate variables
 * PARALLEL : parallel operations
 */

/* This struct is a statement (link) of the iterable object Scope
 * (linked list), that is also a common interface for the various types of
 * statements.
 */
class Statement {
public:
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
	};

	const Type type;

	Statement(Type type, const std::string& text, pointer next);
	virtual ~Statement();

	bool operator==(const Statement& other) const;

	/* accessors */
	void next(pointer next) { m_next = next; }
	pointer next() const { return m_next; }

	void text(const std::string& text) { m_text = text; }
	const std::string& text() const { return m_text; }

private:
	std::string m_text;
	pointer m_next;
};

} /* namespace samb */

#endif /* SRC_DIAGRAM_STATEMENT_H_ */
