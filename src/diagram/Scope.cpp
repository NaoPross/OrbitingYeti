/*
 *  Created on: Nov 28, 2017
 *      Author: naopross
 */

#include "Scope.hpp"

namespace samb {

/* Scope::iterator */

Scope::iterator::iterator(Statement::pointer statement): m_current(statement) {}
Scope::iterator::~iterator() {}

Scope::iterator& Scope::iterator::operator++() {
	if (m_current->next() == nullptr) {
		// TODO: remote throw
		throw std::logic_error("Statement::iterator::operator++() m_current->next() is nullptr");
	}

	m_current = m_current->next();

	return *this;
}

Scope::iterator& Scope::iterator::operator++(int) {
	static Scope::iterator old(*this);

	old = *this;
	operator++();
	return old;
}

Statement& Scope::iterator::operator*() const {
	if (m_current == nullptr) {
		throw std::logic_error("Statement::iterator::operator*() m_current is nullptr");
	}

	return *m_current;
}

Statement::pointer Scope::iterator::operator->() const {
	return m_current;
}


/* Scope */

Scope::Scope(std::string label): Statement(Statement::Type::SCOPE, label, nullptr), m_head(nullptr), m_tail(nullptr) {}
Scope::Scope(std::string label, Statement::pointer first): Statement(Statement::Type::SCOPE, label, first), m_head(first), m_tail(first) {}

Scope::~Scope() {}

Scope::iterator Scope::insert_after(Scope::iterator it, Statement::pointer statement) {
	if (statement == nullptr) {
		throw std::invalid_argument("Statement::insert_after() cannot insert nullptr");
	}

	statement->next(it->next());
	it->next(statement);

	m_size++;

	return it;
}

Scope::iterator Scope::erase_after(Scope::iterator it) {
	if (it->next() == nullptr) {
		return end();
	}

	it->next(it->next()->next());

	return it;
}

} /* namespace samb */
