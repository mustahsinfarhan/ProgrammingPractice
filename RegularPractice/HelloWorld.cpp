#include "../BuildConfig.h"
#include "HelloWorld.h"

#if ACTIVE_BUILD == BUILD_HELLO_WORLD

int run()
{
    std::cout << "Hello World!" << std::endl;

    return 0;
}

#endif