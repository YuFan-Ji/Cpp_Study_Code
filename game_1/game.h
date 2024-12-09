#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Game {
private:
    std::vector<std::vector<int>> board; // ����
    int size;                            // ���̴�С
    int emptyX, emptyY;                  // �ո��λ��

    void shuffle();                      // �����������
    bool isSolvable();                   // �ж������Ƿ�ɽ�
    int getInversionCount() const;       // ����������
    bool isWin() const;                  // �ж��Ƿ�ʤ��

public:
    Game(int n);                         // ���캯��
    void display() const;                // ��ʾ����
    bool move(char direction);           // �ƶ��ո�
    bool checkWin() const;               // ���Ⱪ¶��ʤ�����
    void displayHelp() const;            // ��ʾ������Ϣ
};

#endif
