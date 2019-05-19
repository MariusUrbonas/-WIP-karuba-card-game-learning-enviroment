//
// Created by Marius Urbonas on 2019-05-07.
//

#ifndef CARD_KARUBA_ENVIRONMENT_KARUBA_CARD_H
#define CARD_KARUBA_ENVIRONMENT_KARUBA_CARD_H

#include <string>

namespace card_karuba_env {

class KarubaCard {
public:
    KarubaCard(int rank) : rank_(rank) {}
    KarubaCard() = default;  // Create an invalid card.
    bool operator==(const KarubaCard& other_card) const;
    bool IsValid() const { return rank_ >= 0; }
    std::string ToString() const;
    int Rank() const { return rank_; }
private:
    int rank_ = -1;   // 0 indexed card rank.
};
}

#endif //CARD_KARUBA_ENVIRONMENT_KARUBA_CARD_H

