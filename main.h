#include "build_config.h"

#if ACTIVE_BUILD == BUILD_HELLO_WORLD
    #include "RegularPractice/HelloWorld.h"
#elif ACTIVE_BUILD == BUILD_TICTACTOE
    #include "RegularPractice/TicTacToe.h"
#endif

int run();