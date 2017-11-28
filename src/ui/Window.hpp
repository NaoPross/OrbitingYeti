/*
 * Window.hpp
 *
 *  Created on: Nov 26, 2017
 *      Author: naopross
 */

#ifndef SRC_UI_WINDOW_HPP_
#define SRC_UI_WINDOW_HPP_

#include <QWidget>
#include <QPushButton>

namespace samb {

class Window : public QWidget {
Q_OBJECT
public:
	explicit Window(QWidget *parent = 0);
	~Window();

private:
	QPushButton *m_quitBtn;
};

} /* namespace samb */

#endif /* SRC_UI_WINDOW_HPP_ */
