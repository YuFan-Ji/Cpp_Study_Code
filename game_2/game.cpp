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

    // ��ʼ����Ϸ��ʼʱ��
    startTime = std::chrono::steady_clock::now();

    // ��������
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    generatePuzzle();  // ��������
}

void Game::generatePuzzle() {
    // ��ʼ���������и���Ĭ��Ϊ ' '���ո�
    grid = std::vector<std::vector<char>>(gridSize, std::vector<char>(gridSize, ' '));
    fixedGrid = std::vector<std::vector<char>>(gridSize, std::vector<char>(gridSize, ' '));

    // ���ù̶��ĳ�ʼ����
    grid[1][0] = 'X'; // �ڶ��е�һ����X
    grid[1][5] = 'X'; // �ڶ������һ����X
    grid[2][3] = 'X'; // �����е��ĸ���X
    grid[3][0] = 'O'; // �����е�һ����O
    grid[3][5] = 'X'; // ���������һ����X
    grid[4][1] = 'O'; // �����еڶ�����O
    grid[5][1] = 'O'; // �����еڶ�����O
    grid[5][4] = 'X'; // �����е������X

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] != ' ') {
                fixedGrid[i][j] = grid[i][j]; // ��¼��ʼ�̶�����
            }
        }
    }
}

void Game::handleMouseClick(sf::Vector2i position) {
    float cellSize = 500.0f / gridSize;

    int row = (position.y - 50) / cellSize;
    int col = (position.x - 50) / cellSize;

    if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
        // �������˳�ʼ�Ĺ̶����ӣ����Ե��
        if (fixedGrid[row][col] != ' ') {
            return;
        }

        // �������Ϊ�գ���� 'X'����������
        if (grid[row][col] == ' ') {
            grid[row][col] = 'X';
        }
        else if (grid[row][col] == 'X') {
            grid[row][col] = 'O';
        }
        else if (grid[row][col] == 'O') {
            grid[row][col] = ' ';
        }

        // ������ʷ
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
    // ����Ƿ��г������������� 'X' �� 'O'
    for (int i = 0; i < line.size() - 2; i++) {
        if (line[i] != ' ' && line[i] == line[i + 1] && line[i] == line[i + 2]) {
            return false;
        }
    }

    // ��� X �� O �����Ƿ���ͬ
    int countX = std::count(line.begin(), line.end(), 'X');
    int countO = std::count(line.begin(), line.end(), 'O');
    if (countX != countO) {
        return false;
    }

    return true;
}

bool Game::hasRepeatingRowsOrColumns() {
    // ����Ƿ����ظ����л���
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
    // ���ÿ��
    for (int i = 0; i < gridSize; i++) {
        if (!isValidRowOrColumn(grid[i])) {
            return false;
        }
    }

    // ���ÿ��
    for (int i = 0; i < gridSize; i++) {
        std::vector<char> col;
        for (int j = 0; j < gridSize; j++) {
            col.push_back(grid[j][i]);
        }
        if (!isValidRowOrColumn(col)) {
            return false;
        }
    }

    // ����Ƿ����ظ����л���
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

            // ʹ���ַ� 'X' �� 'O' ����
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
    // ������Ϸ������ʱ��
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();

    std::ostringstream oss;
    oss << "Time: " << elapsed << "s";

    sf::Text timerText(oss.str(), font, 20);
    timerText.setPosition(600, 50);
    timerText.setFillColor(sf::Color::Black);
    window.draw(timerText);

    // ����������ť
    sf::RectangleShape undoButton(sf::Vector2f(100, 40));
    undoButton.setFillColor(sf::Color(200, 200, 200));
    undoButton.setPosition(600, 150);
    window.draw(undoButton);

    // ����������ť����
    sf::Text undoText("Undo", font, 20);
    undoText.setPosition(620, 160);
    undoText.setFillColor(sf::Color::Black);
    window.draw(undoText);

    // �ύ��ť
    sf::RectangleShape submitButton(sf::Vector2f(100, 40));
    submitButton.setFillColor(sf::Color(100, 200, 100));
    submitButton.setPosition(600, 200);
    window.draw(submitButton);

    // �ύ��ť����
    sf::Text submitText("Submit", font, 20);
    submitText.setPosition(620, 210);
    submitText.setFillColor(sf::Color::Black);
    window.draw(submitText);

    // �����ϷӮ�ˣ���ʾʤ����Ϣ
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

                // ������
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
                    undo();  // ���ز���
                }
                else {
                    handleMouseClick(mousePos);  // ��ͨ���
                }
            }
        }

        window.clear(sf::Color::White);
        drawGrid();
        drawUI();
        window.display();
    }
}
