#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Game {
private:
    std::vector<std::vector<int>> board; // 棋盘
    int size;                            // 棋盘大小
    int emptyX, emptyY;                  // 空格的位置

    void shuffle();                      // 随机打乱棋盘
    bool isSolvable();                   // 判断棋盘是否可解
    int getInversionCount() const;       // 计算逆序数
    bool isWin() const;                  // 判断是否胜利

public:
    Game(int n);                         // 构造函数
    void display() const;                // 显示棋盘
    bool move(char direction);           // 移动空格
    bool checkWin() const;               // 对外暴露的胜利检查
    void displayHelp() const;            // 显示帮助信息
};

#endif
