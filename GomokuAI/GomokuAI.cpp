#include <iostream>
#include "board.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Welcome to Lambda Gomoku Game" << endl;
    cout << "Let's compete with an AI." << endl;
    Board board;
    bool player_turn = true;
    while (board.game_running().first) {
        if (player_turn) {
            cout << "Input coordinates(y, x): ";
            int y, x;
            cin >> y >> x;
            board.place_stone(y, x, 1);
        }
        for (int y = 0; y < 19; ++y) {
            cout << '|';
            for (int x = 0; x < 19; ++x) {
                if (board.check_pos(y, x) == 1) cout << 'X';
                else if (board.check_pos(y, x) == 2) cout << 'O';
                else cout << ' ';
            }
            cout << '|' << endl;
        }
    }
    cout << "Game Finished -- player " << board.game_running().second
         << " wins!" << endl;
    return 0;
}
