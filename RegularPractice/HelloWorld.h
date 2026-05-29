#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

#include <iostream>
#include "../BuildTargetDefinition.h"

#if ACTIVE_BUILD == BUILD_HELLO_WORLD
    int run();
#endif

#endif  // HELLO_WORLD_H