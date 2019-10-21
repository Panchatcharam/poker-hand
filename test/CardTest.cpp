//
// Created by Panchatcharam Murugesan on 1/9/19.
//

#include "../include/Card.h"
#include "gtest/gtest.h"

namespace {

    TEST(GetValueTest, GetValue) {
        std::unique_ptr<Card> card(new Card());
        card->SetCardInfo("2H");
        card->Initialize();
        EXPECT_EQ(0, card->GetValue());
    }

    TEST(GetSuitTest, GetSuit) {
        std::unique_ptr<Card> card(new Card());
        card->SetCardInfo("2H");
        card->Initialize();
        EXPECT_EQ('H', card->GetSuit());
    }
}