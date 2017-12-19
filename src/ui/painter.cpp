#include "ui/painter.h"
#include "ui_painter.h"

Painter::Painter(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Painter)
{
    _ui->setupUi(this);
}

Painter::~Painter()
{
    delete _ui;
}
