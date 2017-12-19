#ifndef DIAGRAM_STRUCTOGRAM_H
#define DIAGRAM_STRUCTOGRAM_H

#include "diagram/scope.h"

#include <QString>

namespace samb {

/* A structogram is a specific type of scope, that is the root scope.
 * As a result it contains some metadata informations about the author,
 * date of creation ecc.
 */
class Structogram : public Scope
{
public:
    Structogram(const QString &title, const QString &author);
    virtual ~Structogram();

    /* accessors */
    inline void title(const QString &title) { text(title); }
    inline const QString& title() const { return text(); }

    void author(const QString &author) { _author = author; }
    const QString& author() const { return _author; }

private:
    QString _author;
};

}

#endif /* DIAGRAM_STRUCTOGRAM_H */
