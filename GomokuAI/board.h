#pragma once
#include <utility>
#include <vector>

using std::make_pair;
using std::pair;
using std::vector;

class Board {
private:
    vector<vector<int>> board_v;
public:
    Board();
    Board(vector<vector<int>> vec);
    void place_stone(int y, int x, int type);
    int check_pos(int y, int x);
    vector<vector<int>> raw_data();
    pair<bool, int> game_running();
};