//
// Created by Marius Urbonas on 2019-05-07.
//

#include "karuba_card.h"

#include "util.h"

namespace card_karuba_env {

    bool KarubaCard::operator==(const KarubaCard &other_card) const {
        return other_card.Rank() == Rank();
    }

    std::string KarubaCard::ToString() const {
        if (!IsValid()) {
            return std::string("XX");
        }
        return std::string() + RankIndexToString(Rank());
    }
}