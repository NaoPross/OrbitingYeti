#include "diagram/Statement.hpp"

using namespace samb;

/* Statement */

Statement::Statement(Type t, const std::string& text): type(t), m_text(text), m_next(nullptr) {}
Statement::Statement(Type t, const std::string& text, Statement::pointer p): type(t), m_text(text), m_next(p) {}

Statement::~Statement() {}

bool Statement::operator==(const Statement& other) const {
    // comparison by pointers
    return (this == &other);
}

