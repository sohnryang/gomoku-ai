#pragma once
#include "board.h"

namespace ai {
    vector<pair<int, int>> next_moves(Board board);
    int evaluate_board(Board board);
    pair<int, pair<int, int>> run_ai(Board board, bool ai_turn, int depth,
                                     int alpha, int beta);
}