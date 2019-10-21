//
// Created by Panchatcharam Murugesan on 31/8/19.
//

#ifndef POKER_HAND_POKERPLAY_H
#define POKER_HAND_POKERPLAY_H

#include "PokerHand.h"
#include <string>

class PokerPlay {
private:
    std::unique_ptr<PokerHand> handBlack;
    std::unique_ptr<PokerHand> handWhite;
    bool ValidateInput(std::string input);
    void DetermineWinningHand(std::vector<std::string> & black, std::vector<std::string> & white);
    void PopulatePokerHand(std::vector<std::string> & hand);

public:
    void HandleInput(std::string input);
    PokerPlay();
};

#endif //POKER_HAND_POKERPLAY_H
