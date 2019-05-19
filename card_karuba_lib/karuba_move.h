//
// Created by Marius Urbonas on 2019-05-14.
//

#ifndef CARD_KARUBA_ENVIRONMENT_KARUBA_MOVE_H
#define CARD_KARUBA_ENVIRONMENT_KARUBA_MOVE_H

#include <cstdint>
namespace card_karuba_env{

// Two types of stages:
//      kBid    : Choose 2 cards for initial play
//      kPlay   : Play 2 or 1 cards (depending on outcome of first stage)
class KarubaBidPhase{

public:
    KarubaBidPhase(int8_t card_index1, int8_t card_index2)
private:

};

class KarubaPlacePhase{

public:

private:

};

class KarubaMove{
public:
    enum Phase {kBid, kPlace};

private:

};

}

#endif //CARD_KARUBA_ENVIRONMENT_KARUBA_MOVE_H
