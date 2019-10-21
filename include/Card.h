//
// Created by Panchatcharam Murugesan on 29/8/19.
//

#ifndef POKER_HAND_CARD_H
#define POKER_HAND_CARD_H

#include <map>
#include <string>

class Card
{
private:
    std::string cardInfo;
    int value;
    char suit;

public:
    static const std::map<char, int> card_value_map;

    Card();
    ~Card();
    void Initialize();
    bool operator < (const Card & card) const;
    void SetCardInfo(const std::string & cardInfo);
    int GetValue() const;
    char GetSuit() const;
};
#endif //POKER_HAND_CARD_H
