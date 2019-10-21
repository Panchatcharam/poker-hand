//
// Created by Panchatcharam Murugesan on 29/8/19.
//

#ifndef POKER_HAND_POKERHAND_H
#define POKER_HAND_POKERHAND_H

#include "Card.h"
#include "Common.h"

class PokerHand
{

private:
    std::vector<Card> cards;
    Rank rank;
    int highCardCount{};
    std::vector<int> highCardValue;
    std::string playerName;
    std::map<Rank, std::string> rankMap;

    void InitHand();
    bool CheckFlushOrStraight();
    void DetermineOtherRanks();
    bool IsStraight() const;
    bool IsFlush() const;
    void BuildStraightHighCards();
    void BuildHighCardHighCards();
    std::string GetCardName(int value);

public:
    PokerHand();
    void InitPokerHand(const std::string & name, const std::vector<std::string> & cardInfo);
    void DetermineWinner(const PokerHand& other);
};

#endif //POKER_HAND_POKERHAND_H
