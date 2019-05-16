#include "pch.h"
#include "CppUnitTest.h"
#include "../GomokuAI/board.h"
#include "../GomokuAI/board.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AITest {
	TEST_CLASS(AITest) {
	public:
        TEST_METHOD(TestClassInit) {
            Board* b = new Board();
            Assert::IsNotNull<Board>(b);
            delete b;
            vector<int> vec(19, 1);
            vector<vector<int>> board_v(19, vec);
            Board* b2 = new Board(board_v);
            Assert::IsNotNull<Board>(b2);
            Assert::IsTrue(b2->raw_data() == board_v);
            delete b2;
        }

        TEST_METHOD(TestBoardSize) {
            Board b;
            auto vec = b.raw_data();
            Assert::AreEqual<int>(vec.size(), 19);
            for (int i = 0; i < 19; ++i)
                Assert::AreEqual<int>(vec[i].size(), 19);
        }

        TEST_METHOD(TestGameRunning) {
            vector<int> empty_line(19, 0);
            vector<vector<int>> empty_grid(19, empty_line);
            Board b1(empty_grid);
            Assert::IsTrue(b1.game_running().first);
            vector<vector<int>> straight_h(19, empty_line);
            for (int i = 0; i < 5; ++i) straight_h[0][i] = 1;
            Board b2(straight_h);
            Assert::IsFalse(b2.game_running().first);
            vector<vector<int>> straight_v(19, empty_line);
            for (int i = 0; i < 5; ++i) straight_v[i][0] = 1;
            Board b3(straight_v);
            Assert::IsFalse(b3.game_running().first);
            vector<vector<int>> diag_tl_br(19, empty_line);
            for (int i = 0; i < 5; ++i) diag_tl_br[i][i] = 1;
            Board b4(diag_tl_br);
            Assert::IsFalse(b4.game_running().first);
            vector<vector<int>> diag_tr_bl(19, empty_line);
            for (int i = 0; i < 5; ++i) diag_tr_bl[i][4 - i] = 1;
            Board b5(diag_tr_bl);
            Assert::IsFalse(b5.game_running().first);
            vector<int> full_line(19, 1);
            vector<vector<int>> full_grid(19, full_line);
            Board b6(full_grid);
            Assert::IsFalse(b6.game_running().first);
        }
	};
}
