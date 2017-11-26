/*
 * Window.hpp
 *
 *  Created on: Nov 26, 2017
 *      Author: naopross
 */

#ifndef SRC_UI_WINDOW_HPP_
#define SRC_UI_WINDOW_HPP_

#include <QWidget>

namespace samb {

class Window : public QWidget {
Q_OBJECT
public:
	Window();
	virtual ~Window();

signals:
public slots:
};

} /* namespace samb */

#endif /* SRC_UI_WINDOW_HPP_ */
