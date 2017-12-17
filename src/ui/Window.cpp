/*
 * Window.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: naopross
 */

#include "Window.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>


using namespace samb;

Window::Window(QWidget *parent): QWidget(parent) {
    setWindowTitle("OrbitingYeti");

    QVBoxLayout *vBox = new QVBoxLayout(this);
    QHBoxLayout *hBox = new QHBoxLayout();

    m_quitBtn = new QPushButton("Quit", this);
    connect(m_quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));

    hBox->addWidget(m_quitBtn, 0, Qt::AlignRight);
    vBox->addStretch(1);
    vBox->addLayout(hBox);
}

Window::~Window() {

}
