//
// Created by Panchatcharam Murugesan on 29/8/19.
//
#include "../include/Card.h"

const std::map<char, int> Card::card_value_map = {{'2',0}, {'3',1},{'4',2},
                                                   {'5',3}, {'6',4}, {'7',5},
                                                   {'8',6}, {'9',7},{'T',8},
                                                   {'J',9}, {'Q',10}, {'K',11}, {'A',12}};

Card::Card() = default;
Card::~Card() = default;

void Card::Initialize() {
    value = card_value_map.at(cardInfo[0]);
    suit = cardInfo[1];
}

bool Card::operator < (const Card & card) const {
    return this->value < card.value;
}

void Card::SetCardInfo(const std::string & cardInfo) {
    this->cardInfo = cardInfo;
}

int Card::GetValue() const {
    return this->value;
}

char Card::GetSuit() const {
    return this->suit;
}