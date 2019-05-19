//
// Created by Marius Urbonas on 2019-05-07.
//

#ifndef CARD_KARUBA_ENVIRONMENT_UTIL_H
#define CARD_KARUBA_ENVIRONMENT_UTIL_H

#include <string>

namespace card_karuba_env {

    constexpr int kMaxNumRanks = 16;

    // Returns a character representation of an integer rank index.
    std::string RankIndexToString(int rank);

#if defined(NDEBUG)
    #define REQUIRE(expr)                                                        \
  (expr ? (void)0                                                            \
        : (fprintf(stderr, "Input requirements failed at %s:%d in %s: %s\n", \
                   __FILE__, __LINE__, __func__, #expr),                     \
           std::abort()))
#else
#define REQUIRE(expr) assert(expr)
#endif
}


#endif //CARD_KARUBA_ENVIRONMENT_UTIL_H
