//
// Created by Marius Urbonas on 2019-05-15.
//

#ifndef CARD_KARUBA_ENVIRONMENT_KARUBA_STATE_H
#define CARD_KARUBA_ENVIRONMENT_KARUBA_STATE_H

#include "karuba_card.h"
#include <vector>

namespace card_karuba_env{

class KarubaState{

public:
    class KarubaDeck{
    public:
        explicit KarubaDeck(const KarubaGame &game);
        //Deal cards
        KarubaCard DealCard(int rank);
        KarubaCard DealCard(std::mt19937* rng);
        int Size() const {return total_size_};
        bool Empty() const {return total_size_ == 0};

    private:
        int total_size_ = -1;
    };

    enum EndOfGameType{
        kNotFinished,
        kDone
    };

    explicit KarubaState(const KarubaGame *parent_game);
    KarubaState(const KarubaState &state) = default;

    void ApplyMove(KarubaMove move);
    std::vector<KarubaMove> LegalMoves(int player) const;
    
};

}


#endif //CARD_KARUBA_ENVIRONMENT_KARUBA_STATE_H
