#include <iostream>
#include "../include/PokerPlay.h"
#include <string>

int main() {

    PokerPlay pokerPlay;
    std::string line;
    std::getline (std::cin,line);
    pokerPlay.HandleInput(line);
    return 0;
}