//
// Created by Marius Urbonas on 2019-05-09.
//

#include "karuba_hand.h"

#include <algorithm>
#include <cassert>

#include "util.h"

namespace card_karuba_env {

    void KarubaHand::AddCard(KarubaCard card){

        REQUIRE(card.IsValid());
        cards_.push_back(card);
    }

    void KarubaHand::RemoveFromHand(int card_index, std::vector<card_karuba_env::KarubaCard> *discard_pile) {

        if (discard_pile != nullptr){
            discard_pile->push_back(cards_[card_index]);
        }
        cards_.erase(cards_.begin() + card_index);
    }
}