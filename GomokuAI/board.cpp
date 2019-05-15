#include "board.h"

Board::Board() {
    vector<int> vec(19, 0);
    this->board_v.assign(19, vec);
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