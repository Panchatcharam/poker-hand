//
// Created by Panchatcharam Murugesan on 31/8/19.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "../include/PokerPlay.h"

PokerPlay::PokerPlay() try : handBlack(new PokerHand, std::default_delete<PokerHand>())
                            , handWhite(new PokerHand, std::default_delete<PokerHand>()) {

}
catch(...) {
    std::cout << "Could not create Poker Hands" << std::endl;
}

void PokerPlay::HandleInput(std::string input) {
    std::vector<std::string> tokens;
    std::stringstream data;

    if (ValidateInput(input)) {
        input.erase(std::remove(input.begin(), input.end(), ':'), input.end());
        data << input;
        std::string intermediate;

        while(getline(data, intermediate, ' ')) {
            tokens.push_back(intermediate);
        }

        if (tokens.size() == 12) {
            std::vector<std::string> black(tokens.begin(), tokens.begin() + tokens.size() / 2);
            std::vector<std::string> white(tokens.begin() + tokens.size() / 2 , tokens.end());

            DetermineWinningHand(black, white);
        }

    }
}

bool PokerPlay::ValidateInput(std::string input) {
    if (input.empty()) {
        return false;
    }

    return true;
}

void PokerPlay::DetermineWinningHand(std::vector<std::string> &black, std::vector<std::string> &white) {

    const std::string nameBlack(black[0]);
    const std::string nameWhite(white[0]);

    black.erase(black.begin());
    white.erase(white.begin());

    handBlack->InitPokerHand(nameBlack, black);
    handWhite->InitPokerHand(nameWhite, white);

    handBlack->DetermineWinner(*handWhite.get());
}