#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "请输入棋盘大小（如 3 表示 3x3）：";
    cin >> size;

    Game game(size);

    while (true) {
        game.display();
        if (game.checkWin()) {
            cout << "恭喜你，完成了华容道！\n";
            break;
        }

        cout << "请输入移动方向 (W/A/S/D/H/Q): ";
        char input;
        cin >> input;

        if (toupper(input) == 'Q') {
            cout << "退出游戏。\n";
            break;
        }
        else if (toupper(input) == 'H') {
            game.displayHelp();
        }
        else if (!game.move(toupper(input))) {
            cout << "非法移动，请重新输入！\n";
        }
    }

    return 0;
}
