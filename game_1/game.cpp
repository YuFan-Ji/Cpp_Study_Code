#include "Game.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// 构造函数：初始化棋盘
Game::Game(int n) : size(n) {
    board.resize(n, vector<int>(n));
    int num = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = (num < n * n) ? num++ : 0; // 空格用 0 表示
        }
    }
    emptyX = n - 1;
    emptyY = n - 1;
    shuffle();
}

// 随机打乱棋盘
void Game::shuffle() {
    do {
        vector<int> nums(size * size);
        for (int i = 0; i < size * size; ++i) nums[i] = i;
        random_shuffle(nums.begin(), nums.end());

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                board[i][j] = nums[i * size + j];
                if (board[i][j] == 0) {
                    emptyX = i;
                    emptyY = j;
                }
            }
        }
    } while (!isSolvable()); // 确保生成的棋盘可解
}

// 检查棋盘是否可解
bool Game::isSolvable() {
    int invCount = getInversionCount();
    if (size % 2 != 0) {
        return (invCount % 2 == 0);
    }
    else {
        int emptyRowFromBottom = size - emptyX;
        if (emptyRowFromBottom % 2 == 0) {
            return (invCount % 2 != 0);
        }
        else {
            return (invCount % 2 == 0);
        }
    }
}

// 计算逆序数
int Game::getInversionCount() const {
    vector<int> nums;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell != 0) nums.push_back(cell);
        }
    }
    int invCount = 0;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] > nums[j]) ++invCount;
        }
    }
    return invCount;
}

// 显示棋盘
void Game::display() const {
    system("cls"); 
    cout << "====== 华容道 ======\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == 0)
                cout << setw(4) << " ";
            else
                cout << setw(4) << cell;
        }
        cout << endl;
    }
    cout << "\nW: 上, A: 左, S: 下, D: 右, Q: 退出游戏, H: 帮助\n";
}

// 显示帮助信息
void Game::displayHelp() const {
    cout << "华容道游戏规则：\n"
        << "1. 将棋盘上的数字按升序排列，空格位于右下角。\n"
        << "2. 使用 W/A/S/D 键移动空格。\n"
        << "3. Q 键退出游戏，H 键查看帮助。\n";
}

// 移动空格
bool Game::move(char direction) {
    int newX = emptyX, newY = emptyY;
    switch (direction) {
    case 'W': newX--; break; // 上
    case 'A': newY--; break; // 左
    case 'S': newX++; break; // 下
    case 'D': newY++; break; // 右
    default: return false;
    }
    if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
        swap(board[emptyX][emptyY], board[newX][newY]);
        emptyX = newX;
        emptyY = newY;
        return true;
    }
    return false;
}

// 判断是否胜利
bool Game::isWin() const {
    int target = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == size - 1 && j == size - 1)
                return board[i][j] == 0;
            if (board[i][j] != target++)
                return false;
        }
    }
    return true;
}

// 对外暴露的胜利检查
bool Game::checkWin() const {
    return isWin();
}
