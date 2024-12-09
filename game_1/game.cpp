#include "Game.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// ���캯������ʼ������
Game::Game(int n) : size(n) {
    board.resize(n, vector<int>(n));
    int num = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = (num < n * n) ? num++ : 0; // �ո��� 0 ��ʾ
        }
    }
    emptyX = n - 1;
    emptyY = n - 1;
    shuffle();
}

// �����������
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
    } while (!isSolvable()); // ȷ�����ɵ����̿ɽ�
}

// ��������Ƿ�ɽ�
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

// ����������
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

// ��ʾ����
void Game::display() const {
    system("cls"); 
    cout << "====== ���ݵ� ======\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == 0)
                cout << setw(4) << " ";
            else
                cout << setw(4) << cell;
        }
        cout << endl;
    }
    cout << "\nW: ��, A: ��, S: ��, D: ��, Q: �˳���Ϸ, H: ����\n";
}

// ��ʾ������Ϣ
void Game::displayHelp() const {
    cout << "���ݵ���Ϸ����\n"
        << "1. �������ϵ����ְ��������У��ո�λ�����½ǡ�\n"
        << "2. ʹ�� W/A/S/D ���ƶ��ո�\n"
        << "3. Q ���˳���Ϸ��H ���鿴������\n";
}

// �ƶ��ո�
bool Game::move(char direction) {
    int newX = emptyX, newY = emptyY;
    switch (direction) {
    case 'W': newX--; break; // ��
    case 'A': newY--; break; // ��
    case 'S': newX++; break; // ��
    case 'D': newY++; break; // ��
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

// �ж��Ƿ�ʤ��
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

// ���Ⱪ¶��ʤ�����
bool Game::checkWin() const {
    return isWin();
}
