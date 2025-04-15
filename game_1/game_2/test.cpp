#include "Game.h"
#include <iostream>

int main() {
    try {
        Game game(6); // 创建一个 6x6 的 OOXX 游戏
        game.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
