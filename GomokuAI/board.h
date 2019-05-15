#pragma once
#include <vector>

using std::vector;

class Board {
private:
    vector<vector<int>> board_v;
public:
    Board();
    void place_stone(int y, int x, int type);
    int check_pos(int y, int x);
    vector<vector<int>> raw_data();
    bool game_running();
};