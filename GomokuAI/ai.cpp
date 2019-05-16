#include "ai.h"
#include "global.h"

int ai::evaluate_board(Board board) {
    if (!board.game_running().first)
        return board.game_running().second == 2 ? INF : -INF;
    return 0;
}

pair<int, pair<int, int>> ai::run_ai(Board board, bool ai_turn, int depth,
                                     int alpha, int beta) {
    pair<int, int> best = make_pair(-1, -1);
    int best_score = ai_turn ? -INF : INF;
    if (!board.game_running().first) {
        best_score = evaluate_board(board);
        return make_pair(best_score, best);
    }
    return pair<int, pair<int, int>>();
}