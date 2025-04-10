#include <time.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int randomNum(int num) { return rand() % num; };

class sanmoku {
   private:
    string player;
    string cpu;
    string blank;

   public:
    sanmoku();
    void printBoard();
    int decideOrder();
    void put();
    void cpuPut();
    string judge();
    void play();
    vector<vector<string> > board;
};

sanmoku::sanmoku() {
    player = "o";
    cpu = "x";
    blank = "-";
    board = vector<vector<string> >(3, vector<string>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board.at(i).at(j) = blank;
        }
    }
}

void sanmoku::printBoard() {
    cout << endl
         << "  0 "
         << "1 "
         << "2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int sanmoku::decideOrder() {
    srand((unsigned int)time(NULL));
    int order = randomNum(2);
    if (order == 0) {
        cout << "あなたは先攻です" << endl << endl;
    } else {
        cout << "あなたは後攻です" << endl << endl;
    }
    return order;
}

void sanmoku::put() {
    vector<int> position(2, 0);
    while (1) {
        int line, row;
        cout << "縦方向を入力 : ";
        cin >> line;
        if (line >= 0 && line <= 2) {
            position[0] = line;
        } else {
            cout << endl << "無効な値です" << endl << endl;
            continue;
        }
        cout << "横方向を入力 : ";
        cin >> row;
        if (row >= 0 && row <= 2) {
            if (board.at(line).at(row) != blank) {
                cout << endl << "すでにコマが置かれています" << endl << endl;
                continue;
            } else {
                position[1] = row;
                break;
            }
        } else {
            cout << endl << "無効な値です" << endl << endl;
            continue;
        }
    }
    board.at(position[0]).at(position[1]) = player;
}

void sanmoku::cpuPut() {
    srand((unsigned int)time(NULL));
    vector<int> position;
    while (1) {
        int lineNum = randomNum(3);
        int rowNum = randomNum(3);
        if (board.at(lineNum).at(rowNum) == blank) {
            board.at(lineNum).at(rowNum) = cpu;
            break;
        }
    }
}

string sanmoku::judge() {
    string flag = "";
    for (int i = 0; i < 3; i++) {
        if (board.at(i).at(0) == player && board.at(i).at(1) == player &&
            board.at(i).at(2) == player) {
            flag = player;
            break;
        } else if (board.at(i).at(0) == cpu && board.at(i).at(1) == cpu &&
                   board.at(i).at(2) == cpu) {
            flag = cpu;
            break;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (board.at(0).at(j) == player && board.at(1).at(j) == player &&
            board.at(2).at(j) == player) {
            flag = player;
            break;
        } else if (board.at(0).at(j) == cpu && board.at(1).at(j) == cpu &&
                   board.at(2).at(j) == cpu) {
            flag = cpu;
            break;
        }
    }
    if ((board.at(0).at(0) == player && board.at(1).at(1) == player &&
         board.at(2).at(2) == player) ||
        (board.at(0).at(2) == player && board.at(1).at(1) == player &&
         board.at(2).at(0) == player)) {
        flag = player;
    } else if ((board.at(0).at(0) == cpu && board.at(1).at(1) == cpu &&
                board.at(2).at(2) == cpu) ||
               (board.at(0).at(2) == cpu && board.at(1).at(1) == cpu &&
                board.at(2).at(0) == cpu)) {
        flag = cpu;
    }
    if (flag == player) {
        cout << "あなたの勝利です!" << endl;
    } else if (flag == cpu) {
        cout << "cpuの勝利です!" << endl;
    }
    return flag;
};

void sanmoku::play() {
    printBoard();
    int order = decideOrder();
    if (order == 0) {
        for (int i = 0; i < 9; i++) {
            if (i % 2 == 0) {
                cout << "あなたの番です" << endl;
                put();
                printBoard();
                string flag = judge();
                if (flag == player) {
                    break;
                }

            } else {
                cout << "cpuの番です" << endl;
                cpuPut();
                printBoard();
                string flag = judge();
                if (flag == cpu) {
                    break;
                }
            }
            if (i == 8) {
                cout << "引き分けです" << endl;
            }
        }
    } else {
        for (int i = 0; i < 9; i++) {
            if (i % 2 == 0) {
                cout << "cpuの番です" << endl;
                cpuPut();
                printBoard();
                string flag = judge();
                if (flag == cpu) {
                    break;
                }
            } else {
                cout << "あなたの番です" << endl;
                put();
                printBoard();
                string flag = judge();
                if (flag == player) {
                    break;
                }
            }
            if (i == 8) {
                cout << "引き分けです" << endl;
            }
        }
    }
}

int main() {
    sanmoku game;
    game.play();
    return 0;
}
