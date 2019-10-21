//
// Created by Panchatcharam Murugesan on 29/8/19.
//

#ifndef POKER_HAND_COMMON_H
#define POKER_HAND_COMMON_H
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

enum class Rank {
    INVALID = -1,
    HIGH_CARD,
    PAIR,
    TWO_PAIRS,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
};

const int TOTAL_CARD_VALUE = 13;
const int TOTAL_CARDS_IN_HAND = 5;

#endif //POKER_HAND_COMMON_H
