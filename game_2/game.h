#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
#include <chrono>
#include <string>
#include <set>

class Game {
public:
    Game(int size);
    void run();

private:
    int gridSize;                                 // 网格大小
    std::vector<std::vector<char>> grid;          // 当前网格状态
    std::vector<std::vector<char>> fixedGrid;     // 固定格子
    std::stack<std::vector<std::vector<char>>> history; // 历史记录
    sf::RenderWindow window;                      // 窗口对象
    sf::Font font;                                // 字体

    // 游戏状态
    bool isXTurn;                  // 当前轮到 X
    bool gameWon;                  // 游戏是否胜利

    // 绘制
    void drawGrid();
    void drawUI();

    // 事件处理
    void handleMouseClick(sf::Vector2i position);

    // 功能
    void undo();
    bool checkWin();
    bool isValidMove(int row, int col, char value);
    void generatePuzzle();  // 生成谜题
    bool checkVictoryConditions();  // 检查胜利条件
    bool isValidRowOrColumn(std::vector<char>& line);  // 检查行或列是否符合规则
    bool hasRepeatingRowsOrColumns();  // 检查是否有重复的行或列

private:
    std::chrono::steady_clock::time_point startTime;  // 游戏开始时间
};

#endif // GAME_H
