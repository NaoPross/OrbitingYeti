#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "diagram/structogram.h"

#include <QFileInfo>

class Serializer
{
public:
    explicit Serializer();
    virtual ~Serializer();

    bool write(const samb::Structogram &structogram, QFileInfo into);
    bool load(samb::Structogram &structogram, QFileInfo from);
};

#endif // SERIALIZER_H
