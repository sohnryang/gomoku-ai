#include "board.h"

Board::Board() {
    vector<int> vec(19, 0);
    this->board_v.assign(19, vec);
}

Board::Board(vector<vector<int>> vec) {
    this->board_v = vec;
}

void Board::place_stone(int y, int x, int type) {
    this->board_v[y][x] = type;
}

int Board::check_pos(int y, int x) {
    return this->board_v[y][x];
}

vector<vector<int>> Board::raw_data() {
    return this->board_v;
}

pair<bool, int> Board::game_running() {
    const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            if (this->board_v[i][j] == 0) continue;
            int current = this->board_v[i][j];
            for (int k = 0; k < 8; ++k) {
                bool success = true;
                for (int l = 1; l < 5; ++l) {
                    if (i + dy[k] * l < 0 || i + dy[k] * l >= 19) {
                        success = false;
                        break;
                    }
                    if (j + dx[k] * l < 0 || j + dx[k] * l >= 19) {
                        success = false;
                        break;
                    }
                    if (this->board_v[i + dy[k] * l][j + dx[k] * l] != current) {
                        success = false;
                        break;
                    }
                }
                if (success) return make_pair(false, current);
            }
        }
    }
    return make_pair(true, -1);
}