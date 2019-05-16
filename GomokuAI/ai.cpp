#include <algorithm>
#include "ai.h"
#include "global.h"

using std::max;
using std::min;

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
    pair<int, int> best_move = make_pair(-1, -1);
    int best_score = ai_turn ? -INF : INF;
    if (!board.game_running().first) {
        best_score = evaluate_board(board);
        return make_pair(best_score, best_move);
    }
    vector<pair<int, int>> legal_moves = next_moves(board);
    for (auto move: legal_moves) {
        Board board_copy = board;
        board_copy.place_stone(move.first, move.second, ai_turn ? 2 : 1);
        if (ai_turn) {
            int score = run_ai(board_copy, false, depth + 1, alpha, beta).first;
            if (best_score < score) {
                best_score = score - depth * 10;
                best_move = move;
                alpha = max(alpha, best_score);
                if (beta <= alpha) break;
            }
        } else {
            int score = run_ai(board_copy, true, depth + 1, alpha, beta).first;
            if (best_score > score) {
                best_score = score + depth * 10;
                best_move = move;
                beta = min(beta, best_score);
                if (beta <= alpha) break;
            }
        }
    }
    return make_pair(best_score, best_move);
}