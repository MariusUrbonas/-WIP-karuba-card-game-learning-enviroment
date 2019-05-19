//
// Created by Marius Urbonas on 2019-05-07.
//

#include "util.h"

#include <string>
#include <vector>

namespace card_karuba_env {

    std::string RankIndexToString(int rank) {
        if (rank >= 0 && rank <= kMaxNumRanks) {
            std::vector<std::string> str_ranks = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13",
                                                  "14", "15", "16"};
            return str_ranks[rank];
        } else {
            return "X";
        }
    }
}