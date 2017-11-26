/*
 * Renderer.h
 *
 *  Created on: Nov 23, 2017
 *      Author: naopross
 */

#ifndef SRC_UI_ASCIIRENDERER_HPP_
#define SRC_UI_ASCIIRENDERER_HPP_

#include "../diagram/Structogram.hpp"

namespace samb {

/* Sample renderer for debug,
 *
 * TODO: implement PdfRenderer, UiRenderer with a common interface
 */
class AsciiRenderer {
private:
	Structogram m_structogram;
	const unsigned int m_width;

	void drawPadding(unsigned int amt);
	void drawLine() const;
	void drawText(std::string text, unsigned int width = 0, std::string before = "|", std::string after = "|") const;
	void drawDecision(std::string condition, std::string trueText, std::string falseText, unsigned int width = 0) const;
public:
	AsciiRenderer(Structogram& structogram, unsigned int width);
	~AsciiRenderer();

	void render();
};

} /* namespace samb */

#endif /* SRC_UI_ASCIIRENDERER_HPP_ */
