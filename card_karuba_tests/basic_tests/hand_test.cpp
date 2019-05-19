//
// Created by Marius Urbonas on 2019-05-13.
//

#include "gtest/gtest.h"
#include "karuba_hand.h"
#include <stdlib.h>

card_karuba_env::KarubaCard SetupRandomCard(){
    int randIdx = rand() % 16 + 1;
    card_karuba_env::KarubaCard card(randIdx);
    return card;
}

TEST(karuba_hand_test, hand_basic){
    card_karuba_env::KarubaCard card = SetupRandomCard();
    card_karuba_env::KarubaHand hand;
    hand.AddCard(card);
}

TEST(karuba_hand_test, hand_basic2){

}