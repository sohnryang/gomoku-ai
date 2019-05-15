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
        }
	};
}
