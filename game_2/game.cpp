#include "Game.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <set>

Game::Game(int size)
    : gridSize(size),
    window(sf::VideoMode(800, 600), "OOXX Game"),
    isXTurn(true),
    gameWon(false) {

    grid.resize(gridSize, std::vector<char>(gridSize, ' '));
    fixedGrid.resize(gridSize, std::vector<char>(gridSize, ' '));

    // 初始化游戏开始时间
    startTime = std::chrono::steady_clock::now();

    // 加载字体
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    generatePuzzle();  // 生成谜题
}

void Game::generatePuzzle() {
    // 初始化网格，所有格子默认为 ' '（空格）
    grid = std::vector<std::vector<char>>(gridSize, std::vector<char>(gridSize, ' '));
    fixedGrid = std::vector<std::vector<char>>(gridSize, std::vector<char>(gridSize, ' '));

    // 设置固定的初始格子
    grid[1][0] = 'X'; // 第二行第一个是X
    grid[1][5] = 'X'; // 第二行最后一个是X
    grid[2][3] = 'X'; // 第三行第四个是X
    grid[3][0] = 'O'; // 第四行第一个是O
    grid[3][5] = 'X'; // 第四行最后一个是X
    grid[4][1] = 'O'; // 第五行第二个是O
    grid[5][1] = 'O'; // 第六行第二个是O
    grid[5][4] = 'X'; // 第六行第五个是X

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] != ' ') {
                fixedGrid[i][j] = grid[i][j]; // 记录初始固定格子
            }
        }
    }
}

void Game::handleMouseClick(sf::Vector2i position) {
    float cellSize = 500.0f / gridSize;

    int row = (position.y - 50) / cellSize;
    int col = (position.x - 50) / cellSize;

    if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
        // 如果点击了初始的固定格子，忽略点击
        if (fixedGrid[row][col] != ' ') {
            return;
        }

        // 如果格子为空，填充 'X'，依此类推
        if (grid[row][col] == ' ') {
            grid[row][col] = 'X';
        }
        else if (grid[row][col] == 'X') {
            grid[row][col] = 'O';
        }
        else if (grid[row][col] == 'O') {
            grid[row][col] = ' ';
        }

        // 保存历史
        history.push(grid);
    }
}

void Game::undo() {
    if (!history.empty()) {
        grid = history.top();
        history.pop();
        isXTurn = !isXTurn;
        gameWon = false;
    }
}

bool Game::isValidRowOrColumn(std::vector<char>& line) {
    // 检查是否有超过两个连续的 'X' 或 'O'
    for (int i = 0; i < line.size() - 2; i++) {
        if (line[i] != ' ' && line[i] == line[i + 1] && line[i] == line[i + 2]) {
            return false;
        }
    }

    // 检查 X 和 O 数量是否相同
    int countX = std::count(line.begin(), line.end(), 'X');
    int countO = std::count(line.begin(), line.end(), 'O');
    if (countX != countO) {
        return false;
    }

    return true;
}

bool Game::hasRepeatingRowsOrColumns() {
    // 检查是否有重复的行或列
    std::set<std::vector<char>> rows;
    std::set<std::vector<char>> cols;

    for (int i = 0; i < gridSize; i++) {
        if (!rows.insert(grid[i]).second) {
            return true;
        }

        std::vector<char> col;
        for (int j = 0; j < gridSize; j++) {
            col.push_back(grid[j][i]);
        }
        if (!cols.insert(col).second) {
            return true;
        }
    }

    return false;
}

bool Game::checkVictoryConditions() {
    // 检查每行
    for (int i = 0; i < gridSize; i++) {
        if (!isValidRowOrColumn(grid[i])) {
            return false;
        }
    }

    // 检查每列
    for (int i = 0; i < gridSize; i++) {
        std::vector<char> col;
        for (int j = 0; j < gridSize; j++) {
            col.push_back(grid[j][i]);
        }
        if (!isValidRowOrColumn(col)) {
            return false;
        }
    }

    // 检查是否有重复的行或列
    if (hasRepeatingRowsOrColumns()) {
        return false;
    }

    return true;
}

void Game::drawGrid() {
    float cellSize = 500.0f / gridSize;
    sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
    cell.setFillColor(sf::Color::Transparent);
    cell.setOutlineThickness(1);
    cell.setOutlineColor(sf::Color::Black);

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cell.setPosition(50 + j * cellSize, 50 + i * cellSize);
            window.draw(cell);

            // 使用字符 'X' 或 'O' 绘制
            if (grid[i][j] == 'X') {
                sf::Text xText("X", font, 50);
                xText.setPosition(50 + j * cellSize, 50 + i * cellSize);
                xText.setFillColor(sf::Color::Black);
                window.draw(xText);
            }
            else if (grid[i][j] == 'O') {
                sf::Text oText("O", font, 50);
                oText.setPosition(50 + j * cellSize, 50 + i * cellSize);
                oText.setFillColor(sf::Color::Black);
                window.draw(oText);
            }
        }
    }
}

void Game::drawUI() {
    // 计算游戏经过的时间
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();

    std::ostringstream oss;
    oss << "Time: " << elapsed << "s";

    sf::Text timerText(oss.str(), font, 20);
    timerText.setPosition(600, 50);
    timerText.setFillColor(sf::Color::Black);
    window.draw(timerText);

    // 创建撤销按钮
    sf::RectangleShape undoButton(sf::Vector2f(100, 40));
    undoButton.setFillColor(sf::Color(200, 200, 200));
    undoButton.setPosition(600, 150);
    window.draw(undoButton);

    // 创建撤销按钮文字
    sf::Text undoText("Undo", font, 20);
    undoText.setPosition(620, 160);
    undoText.setFillColor(sf::Color::Black);
    window.draw(undoText);

    // 提交按钮
    sf::RectangleShape submitButton(sf::Vector2f(100, 40));
    submitButton.setFillColor(sf::Color(100, 200, 100));
    submitButton.setPosition(600, 200);
    window.draw(submitButton);

    // 提交按钮文字
    sf::Text submitText("Submit", font, 20);
    submitText.setPosition(620, 210);
    submitText.setFillColor(sf::Color::Black);
    window.draw(submitText);

    // 如果游戏赢了，显示胜利信息
    if (gameWon) {
        sf::Text winText("You Win!", font, 30);
        winText.setPosition(300, 550);
        winText.setFillColor(sf::Color::Green);
        window.draw(winText);
    }
}


void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && !gameWon) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // 处理点击
                if (mousePos.x >= 600 && mousePos.x <= 700 && mousePos.y >= 200 && mousePos.y <= 240) {
                    if (checkVictoryConditions()) {
                        gameWon = true;
                    }
                    else {
                        sf::Text loseText("Don't be discouraged, try again!", font, 30);
                        loseText.setPosition(300, 550);
                        loseText.setFillColor(sf::Color::Red);
                        window.draw(loseText);
                    }
                }
                else if (mousePos.x >= 600 && mousePos.x <= 700 && mousePos.y >= 150 && mousePos.y <= 190) {
                    undo();  // 撤回操作
                }
                else {
                    handleMouseClick(mousePos);  // 普通点击
                }
            }
        }

        window.clear(sf::Color::White);
        drawGrid();
        drawUI();
        window.display();
    }
}
