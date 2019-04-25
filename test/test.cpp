#include "gtest/gtest.h"

#include "2048.h"
#include "PrintfUI.h"
class GameTester : public Game2048, public testing::Test {

// TODO: set function;
};

TEST(TestCaseName, TestName) { EXPECT_TRUE(true); }

TEST(TestCaseName, TestName_xxx) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(TestUI, PrintfUI) {
    PrintfUI ui;
    Matrix input;
    for (int i = 0; i < 4; i++) {
        input.push_back({2, 4, 8, 16});
    }

    ui.setBoard(input);
    ui.show();
}

TEST(TestGame2048, TestStep) {
    Game2048 game;
    game.receivedDirect(Direction::UP);
}

TEST(TestGame2048, TestMergeTile) {
    Game2048 game;
    printf("left:\n");
    game.receivedDirect(Direction::LEFT);
    printf("up:\n");
    game.receivedDirect(Direction::UP);
    printf("right:\n");
    game.receivedDirect(Direction::RIGHT);
    printf("down:\n");
    game.receivedDirect(Direction::DOWN);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}