#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "���������̴�С���� 3 ��ʾ 3x3����";
    cin >> size;

    Game game(size);

    while (true) {
        game.display();
        if (game.checkWin()) {
            cout << "��ϲ�㣬����˻��ݵ���\n";
            break;
        }

        cout << "�������ƶ����� (W/A/S/D/H/Q): ";
        char input;
        cin >> input;

        if (toupper(input) == 'Q') {
            cout << "�˳���Ϸ��\n";
            break;
        }
        else if (toupper(input) == 'H') {
            game.displayHelp();
        }
        else if (!game.move(toupper(input))) {
            cout << "�Ƿ��ƶ������������룡\n";
        }
    }

    return 0;
}
