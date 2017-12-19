#ifndef DIAGRAM_STRUCTOGRAM_H
#define DIAGRAM_STRUCTOGRAM_H

#include "diagram/scope.h"

#include <QString>

namespace samb {

class Structogram : public Scope
{
public:
    Structogram(const QString &title, const QString &author);
    ~Structogram();

    /* accessors */
    void title(const QString &title) { text(title); }
    const QString& title() const { return text(); }

    void author(const QString &author) { _author = author; }
    const QString& author() const { return _author; }

private:
    QString _author;
};

}

#endif /* DIAGRAM_STRUCTOGRAM_H */
