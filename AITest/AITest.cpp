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
