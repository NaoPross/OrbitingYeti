#ifndef PAINTER_H
#define PAINTER_H

#include "diagram/statement.h"
#include "diagram/structogram.h"

#include <QWidget>
#include <QFont>
#include <QFontMetrics>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

class Painter : public QWidget
{
    Q_OBJECT

public:
    explicit Painter(QWidget *parent = 0);
    ~Painter();

    void structogram(samb::Structogram **structogram) { _structogram = structogram; }
    const samb::Structogram structogram() const { return **_structogram; }

protected:
    void paintEvent(QPaintEvent *event);

private:
    samb::Structogram **_structogram = nullptr;
    QFont _font;
    QFontMetrics _fontMetrics;

    int _margin = 10;

    void drawStatement(QPainter &qp, samb::Statement &statement, const QRect &rect);
};

#endif // PAINTER_H
