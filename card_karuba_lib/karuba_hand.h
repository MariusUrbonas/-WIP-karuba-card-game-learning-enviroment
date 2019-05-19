//
// Created by Marius Urbonas on 2019-05-09.
//

#ifndef CARD_KARUBA_ENVIRONMENT_KARUBA_HAND_H
#define CARD_KARUBA_ENVIRONMENT_KARUBA_HAND_H


#include <cstdint>
#include <string>
#include <vector>

#include "karuba_card.h"

namespace card_karuba_env{

class KarubaHand{

public:

    void AddCard(KarubaCard card);

    void RemoveFromHand(int card_index, std::vector<KarubaCard>* discard_pile);

private:
    // A set of cards and knowledge about them.
    std::vector<KarubaCard> cards_;

};

}

#endif //CARD_KARUBA_ENVIRONMENT_KARUBA_HAND_H
