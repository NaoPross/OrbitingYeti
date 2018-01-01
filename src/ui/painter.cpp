#include "ui/painter.h"

#include "debugtools.h"

#include <cmath>


Painter::Painter(QWidget *parent) :
    QWidget(parent),
    _font("Latin Modern Roman"),
    _fontMetrics(_font)
{
    // default font size
    _font.setPixelSize(15);
}

Painter::~Painter()
{

}

void Painter::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if (_structogram == nullptr) {
        return;
    }

    if (*_structogram == nullptr) {
        return;
    }

    QPainter qp(this);
    qp.setFont(_font);

    // TODO default values should not be magic numbers
    QRect rect(50, 50, 600, 00);
    for (auto it = (*_structogram)->begin(); it != (*_structogram)->end(); ++it) {
        drawStatement(qp, *it, rect);
        rect.setY(rect.y() + rect.height());
    }
}

void Painter::drawStatement(QPainter &qp, samb::Statement &statement, const QRect &rect)
{
    QRect textRect(rect.x() + _margin,
                   rect.y() + _margin,
                   rect.width() - 2*_margin,
                   rect.height() - 2*_margin);

    int textHeight;
    if (textRect.width() < _fontMetrics.width(statement.text())) {
        textHeight = (_fontMetrics.height() + _fontMetrics.lineSpacing()) *
                        (int) ceil(_fontMetrics.width(statement.text()) / (double) textRect.width());
    } else {
        textHeight = _fontMetrics.height();
    }

    if (textRect.height() < textHeight) {
        debug_msg("painter error, textRect.height() < height");
    }

    qp.drawRect(rect);
    qp.drawText(textRect, Qt::AlignVCenter, statement.text());
}
