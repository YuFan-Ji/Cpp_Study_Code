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
    int gridSize;                                 // �����С
    std::vector<std::vector<char>> grid;          // ��ǰ����״̬
    std::vector<std::vector<char>> fixedGrid;     // �̶�����
    std::stack<std::vector<std::vector<char>>> history; // ��ʷ��¼
    sf::RenderWindow window;                      // ���ڶ���
    sf::Font font;                                // ����

    // ��Ϸ״̬
    bool isXTurn;                  // ��ǰ�ֵ� X
    bool gameWon;                  // ��Ϸ�Ƿ�ʤ��

    // ����
    void drawGrid();
    void drawUI();

    // �¼�����
    void handleMouseClick(sf::Vector2i position);

    // ����
    void undo();
    bool checkWin();
    bool isValidMove(int row, int col, char value);
    void generatePuzzle();  // ��������
    bool checkVictoryConditions();  // ���ʤ������
    bool isValidRowOrColumn(std::vector<char>& line);  // ����л����Ƿ���Ϲ���
    bool hasRepeatingRowsOrColumns();  // ����Ƿ����ظ����л���

private:
    std::chrono::steady_clock::time_point startTime;  // ��Ϸ��ʼʱ��
};

#endif // GAME_H
