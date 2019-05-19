//
// Created by Marius Urbonas on 2019-05-13.
//

#include "gtest/gtest.h"
#include "karuba_card.h"

TEST(karuba_card_test, card_empty){
    card_karuba_env::KarubaCard card_def;
    card_karuba_env::KarubaCard card (2);
    EXPECT_FALSE(card_def.IsValid());
    EXPECT_TRUE(card.IsValid());
    EXPECT_EQ(2, card.Rank());
    EXPECT_NE(2, card_def.Rank());

}

TEST(karuba_card_test, card_basic){
    card_karuba_env::KarubaCard card_def;
    card_karuba_env::KarubaCard card (2);
    EXPECT_FALSE(card_def.IsValid());
    EXPECT_TRUE(card.IsValid());
    EXPECT_EQ(2, card.Rank());
    EXPECT_NE(2, card_def.Rank());
}