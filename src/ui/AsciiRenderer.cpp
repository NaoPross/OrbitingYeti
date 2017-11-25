/*
 * Renderer.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: naopross
 */

#include "AsciiRenderer.h"

#include <memory>

namespace samb {

AsciiRenderer::AsciiRenderer(Structogram& structogram, unsigned int width):
		m_structogram(structogram), m_width(width) {}

AsciiRenderer::~AsciiRenderer() {}

void AsciiRenderer::drawPadding(unsigned int amt) {
	while (amt--) {
		std::cout << " ";
	}
}

void AsciiRenderer::drawLine() const {
	for (unsigned int i = 0; i < m_width; i++) {
		std::cout << "-";
	}

	std::cout << std::endl;
}

void AsciiRenderer::drawText(std::string text, unsigned int width, std::string before, std::string after) const {

	if (width == 0) {
		width = m_width;
	}

	unsigned int textWidth = width - before.length() - after.length();


	std::cout << before;
	for (unsigned int i = 0; i < text.length(); i++) {
		if (i % textWidth == 0) {
			std::cout << after <<  "\n" << before;
		}

		std::cout << text[i];
	}

	std::cout << std::endl;
}

void AsciiRenderer::drawDecision(std::string condition, std::string trueText, std::string falseText, unsigned int width) const {
	if (width == 0) {
		width = m_width -2;
	}

	std::cout << "|";

//	drawPadding(width - condition.length());
}

void AsciiRenderer::render() {
	const std::list<Statement>& statements = m_structogram.getStatements();

	for (std::list<Statement>::const_iterator it = statements.begin(); it != statements.end(); it++) {
		Statement st = *it;
		switch (st.type) {
		case Statement::Type::PROCESS:
			drawLine();
			drawText(st.text);
			break;

		case Statement::Type::DECISION:
			drawLine();
			break;

		case Statement::Type::SWITCH:
			break;

		case Statement::Type::SCOPE:
			break;

		case Statement::Type::WHILE:
			break;

		case Statement::Type::UNTIL:
			break;

		case Statement::Type::PARALLEL:
			break;
		}
	}
}

} /* namespace samb */
