#include "io/serializer.h"
#include "diagram/statement.h"

#include "debugtools.h"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

bool Serializer::write(const samb::Structogram &structogram, const QFileInfo &into)
{
    for (auto it = structogram.begin(); it != structogram.end(); ++it) {
        switch (it->type) {
        case samb::Statement::Type::PROCESS:
            break;

        case samb::Statement::Type::DECISION:
        case samb::Statement::Type::SWITCH:
        case samb::Statement::Type::PARALLEL:
            break;

        case samb::Statement::Type::WHILE:
        case samb::Statement::Type::UNTIL:
            break;

        case samb::Statement::Type::SCOPE:
            break;

        default:
            debug_err("invalid statement type");
            break;
        }
    }

    return true;
}
