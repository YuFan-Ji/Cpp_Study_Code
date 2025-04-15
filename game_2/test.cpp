#include "Game.h"
#include <iostream>

int main() {
    try {
        Game game(6); // ����һ�� 6x6 �� OOXX ��Ϸ
        game.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
