#include "Modpack.h"

Modpack &Modpack::instance()
{
    static Modpack mp;
    return mp;
}