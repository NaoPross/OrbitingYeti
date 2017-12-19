#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>

namespace Ui {
class Painter;
}

class Painter : public QWidget
{
    Q_OBJECT

public:
    explicit Painter(QWidget *parent = 0);
    ~Painter();

private:
    Ui::Painter *_ui;
};

#endif // PAINTER_H
