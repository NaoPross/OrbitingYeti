#ifndef DIAGRAM_STATEMENT_H
#define DIAGRAM_STATEMENT_H

#include <string>
#include <memory>

#include <QString>

namespace samb {

/*  Possible types of statement, according to the NS diagram paper
 * 
 * PROCESS  : a statement that does something
 * SCOPE    : simple scope to isolate variables
 * DECISION : splits the program in 2 branches based on a condition
 * SWITCH   : splits the program in n branches depending on a value
 * WHILE    : check first loop
 * UNTIL    : check last loop
 * PARALLEL : parallel operations
 */

/* This struct is a statement (link) of the iterable object Scope
 * (linked list), that is also a common interface for the various types of
 * statements.
 */
class Statement
{
public:
//    using pointer = std::shared_ptr<Statement>;
    using pointer = Statement*;

    enum Type {
        PROCESS,
        SCOPE,
        DECISION,
        SWITCH,
        WHILE,
        UNTIL,
        PARALLEL,
    };

    const Type type;

    template<class... Args>
    static pointer make(Type t, Args&& ...args);

    Statement(Type t, const QString &text);
    Statement(Type t, const QString &text, pointer next);
    virtual ~Statement();

    bool operator==(const Statement& other) const;

    /* accessors */
    void next(pointer next) { _next = next; }
    pointer next() const { return _next; }

    void text(const QString &text) { _text = text; }
    const QString& text() const { return _text; }

private:
    QString _text;
    pointer _next;
};

} /* namespace samb */

#endif /* DIAGRAM_STATEMENT_H */
