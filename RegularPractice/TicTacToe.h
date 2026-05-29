#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <ctime>
#include "../BuildTargetDefinition.h"

#if ACTIVE_BUILD == BUILD_TICTACTOE
    void drawBoard(char *spaces);
    void playerMove(char *spaces, char player);
    void computerMove(char *spaces, char computer);
    bool checkWinner(char *spaces, char player, char computer);
    bool checkTie(char *spaces);
    int run();
#endif

#endif // TIC_TAC_TOE_H