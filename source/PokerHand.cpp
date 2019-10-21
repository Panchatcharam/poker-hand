//
// Created by Panchatcharam Murugesan on 29/8/19.
//
#include "../include/Common.h"
#include "../include/PokerHand.h"
#include "../include/Card.h"
#include <algorithm>

PokerHand::PokerHand() try : cards(TOTAL_CARDS_IN_HAND, {}),
                        highCardValue(TOTAL_CARDS_IN_HAND, 0),
                        rank(Rank::INVALID),
                         playerName("FAKE"){
    rankMap = {
            {Rank::HIGH_CARD,       "High Card"},
            {Rank::PAIR,            "Pair"},
            {Rank::TWO_PAIRS,       "Two Pairs"},
            {Rank::THREE_OF_A_KIND, "Three of a Kind"},
            {Rank::STRAIGHT,        "Straight"},
            {Rank::FLUSH,           "Flush"},
            {Rank::FULL_HOUSE,      "Full House"},
            {Rank::FOUR_OF_A_KIND,  "Four of a Kind"},
            {Rank::STRAIGHT_FLUSH,  "Straight Flush"}
    };
}
catch(...)
{

}

void PokerHand::InitPokerHand(const std::string &name, const std::vector<std::string> &cardInfo) {

    playerName = name;

    for (int index = 0; index < TOTAL_CARDS_IN_HAND; ++index) {
        cards[index].SetCardInfo(cardInfo[index]);
    }

    InitHand();

    CheckFlushOrStraight() ? void() : DetermineOtherRanks();
}

void PokerHand::InitHand()
{
    for (auto & card : cards) {
        card.Initialize();
    }

    std::sort(cards.begin(),cards.end());
    std::reverse(cards.begin(),cards.end());
    rank = Rank::INVALID;
    highCardCount = -1;
}

bool PokerHand::CheckFlushOrStraight()
{
    bool status = false;
    bool flush = IsFlush();

    if (IsStraight())
    {
        rank = flush ? Rank::STRAIGHT_FLUSH : Rank::STRAIGHT;
        BuildStraightHighCards();
        status = true;
    }
    else if (flush)
    {
        rank = Rank::FLUSH;
        BuildHighCardHighCards();
        status = true;
    }

    return status;
}

void PokerHand::DetermineOtherRanks()
{
    int card_value_freq[TOTAL_CARD_VALUE] = {0};
    for(const auto & card : cards)
    {
        card_value_freq[card.GetValue()]++;
    }

    std::vector<int> four;
    std::vector<int> three;
    std::vector<int> pair;
    for (auto i = 0; i < TOTAL_CARD_VALUE; i++)
    {
        if (card_value_freq[i] == 4)
        {
            four.push_back(i);
        }
        else if (card_value_freq[i] == 3)
        {
            three.push_back(i);
        }
        else if (card_value_freq[i] == 2)
        {
            pair.push_back(i);
        }
    }

    if (!four.empty())
    {
        rank = Rank::FOUR_OF_A_KIND;
        highCardCount = 1;
        highCardValue[0] = four[0];
    }
    else if (!three.empty())
    {
        rank = (pair.size()) ? Rank::FULL_HOUSE : Rank::THREE_OF_A_KIND;
        highCardCount = 1;
        highCardValue[0] = three[0];
    }
    else if (pair.size() == 2)
    {
        rank = Rank::TWO_PAIRS;
        highCardCount = 3;
        if (pair[0] < pair[1])
        {
            highCardValue[0] = pair[0];
            highCardValue[1] = pair[1];
        }
        else
        {
            highCardValue[0] = pair[1];
            highCardValue[1] = pair[0];
        }
        for (auto i = 0; i < TOTAL_CARD_VALUE; i++)
        {
            if (card_value_freq[i] == 1)
            {
                highCardValue[2] = i;
            }
        }
    }
    else if (pair.size() == 1)
    {
        rank = Rank::PAIR;
        highCardCount = 4;
        highCardValue[0] = pair[0];
        int pos = 1;
        for (auto i = 0; i < TOTAL_CARD_VALUE; i++)
        {
            if (card_value_freq[i] == 1)
            {
                highCardValue[pos] = i;
                pos++;
            }
        }
    }
    else
    {
        rank = Rank::HIGH_CARD;
        highCardCount = 5;
        int pos = 0;
        for (auto i = 0; i < TOTAL_CARD_VALUE; i++)
        {
            if (card_value_freq[i] == 1)
            {
                highCardValue[pos] = i;
                pos++;
            }
        }
    }

    std::reverse(highCardValue.begin(),highCardValue.end());
}

// Hand contains 5 cards with consecutive values.
bool PokerHand::IsStraight() const
{
    std::vector<bool> visited(TOTAL_CARD_VALUE, false);
    unsigned int consecutiveCount = 0;

    for (const auto & card : cards)
    {
        visited[card.GetValue()] = true;
    }

    for (const auto & status : visited) {
        if (status) {
            if (++consecutiveCount == 5 )
            {
                return true;
            }
        } else {
            consecutiveCount = 0;
        }
    }

    return false;
}

bool PokerHand::IsFlush() const
{
    // Hand contains 5 cards of the same suit.
    return std::all_of(cards.begin(), cards.end(), [&](const Card& card) {
        return card.GetSuit() == cards[0].GetSuit();
    });
}

void PokerHand::BuildStraightHighCards()
{
    highCardCount = 1;
    highCardValue[0] = cards.back().GetValue();
}

void PokerHand::BuildHighCardHighCards()
{
    highCardCount = 5;
    for (auto index = 0; index < highCardCount ; ++index) {
        highCardValue[index] = cards[index].GetValue();
    }
}

void PokerHand::DetermineWinner(const PokerHand &that) {
    bool valuesEqual = true;
    std::string name;
    std::string rankValue;
    std::string cardValue;
    if (this->rank != that.rank)
    {
        if (this->rank > that.rank) {
            name = this->playerName;
            rankValue = rankMap.at(this->rank);
        } else {
            name = that.playerName;
            rankValue = rankMap.at(that.rank);
        }

        std::cout << name << " " << "wins - with " << rankValue << std::endl;
        return;;
    }

    for (int i = 0; i < highCardCount; i++)
    {
        if (this->highCardValue[i] != that.highCardValue[i])
        {
            valuesEqual = false;
            if (this->highCardValue[i] > that.highCardValue[i]) {
                name = this->playerName;
                rankValue = rankMap.at(this->rank);
                cardValue = GetCardName(this->highCardValue[i]);
                break;
            } else {
                name = that.playerName;
                rankValue = rankMap.at(that.rank);
                cardValue = GetCardName(that.highCardValue[i]);
                break;
            }
        }
    }

    if (valuesEqual) {
        std::cout << "Tie" << std::endl;
    } else {
        std::cout << name << " " << "wins - with " << rankValue  << " : " << cardValue << std::endl;
    }
}

std::string PokerHand::GetCardName(int value) {

    auto it = std::find_if(Card::card_value_map.begin(), Card::card_value_map.end(), [&value](const std::pair<char, int> &p) {
        return p.second == value;
    });

    if (it != Card::card_value_map.end()) {
        switch(it->first) {
            case 'T':
                return "Ten";
            case 'J':
                return "Jack";
            case 'Q':
                return "Queen";
            case 'K':
                return "K";
            case 'A':
                return "Ace";
            default:
                return std::string(1, it->first);;
        }
    } else {
        return "";
    }
}
