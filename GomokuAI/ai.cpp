#include "ai.h"
#include "global.h"

vector<pair<int, int>> ai::next_moves(Board board) {
    vector<pair<int, int>> result;
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            if (board.check_pos(i, j) != 0) continue;
            bool legit = false;
            for (int k = 0; k < 8; ++k)
                if (board.check_pos(i + dy[k], j + dx[k]) != 0)
                    legit = true;
            if (legit) result.push_back(make_pair(i, j));
        }
    }
    return result;
}

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