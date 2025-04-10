#include <time.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int randomNum(int num) { return rand() % num; };

class game {
   private:
    string player;
    string enemy;
    string goal;
    string blank;
    string death;
    vector<int> position;

   public:
    vector<vector<string> > map;
    game();
    void makeMap();
    void printMap();
    void move();
    void play();
};

game::game() {
    player = "P";
    enemy = "E";
    goal = "G";
    blank = "□";
    death = "-";
    position = vector<int>(2, 0);
    map = vector<vector<string> >(8, vector<string>(8));
}

void game::makeMap() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0 && j == 0) {
                map.at(i).at(j) = player;
            } else if (i == 7 && j == 7) {
                map.at(i).at(j) = goal;
            } else {
                if (randomNum(10) == 1) {
                    map.at(i).at(j) = enemy;
                } else {
                    map.at(i).at(j) = blank;
                }
            }
        }
    }
}

void game::printMap() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << map.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

void game::move() {
    string key;
    cout << "キー入力 ";
    cin >> key;
    if (key == "d") {
        if (position[1] == 7) {
            cout << "これ以上進めません" << endl;
        } else {
            position[1] += 1;
            if (map.at(position[0]).at(position[1]) == enemy) {
                map.at(position[0]).at(position[1]) = death;
                map.at(position[0]).at(position[1] - 1) = blank;
            } else {
                map.at(position[0]).at(position[1]) = player;
                map.at(position[0]).at(position[1] - 1) = blank;
            }
        }
    } else if (key == "a") {
        if (position[1] == 0) {
            cout << "これ以上進めません" << endl;
        } else {
            position[1] -= 1;
            if (map.at(position[0]).at(position[1]) == enemy) {
                map.at(position[0]).at(position[1]) = death;
                map.at(position[0]).at(position[1] + 1) = blank;
            } else {
                map.at(position[0]).at(position[1]) = player;
                map.at(position[0]).at(position[1] + 1) = blank;
            }
        }
    } else if (key == "s") {
        if (position[0] == 7) {
            cout << "これ以上進めません" << endl;
        } else {
            position[0] += 1;
            if (map.at(position[0]).at(position[1]) == enemy) {
                map.at(position[0]).at(position[1]) = death;
                map.at(position[0] - 1).at(position[1]) = blank;
            } else {
                map.at(position[0]).at(position[1]) = player;
                map.at(position[0] - 1).at(position[1]) = blank;
            }
        }
    } else if (key == "w") {
        if (position[0] == 0) {
            cout << "これ以上進めません" << endl;
        } else {
            position[0] -= 1;
            if (map.at(position[0]).at(position[1]) == enemy) {
                map.at(position[0]).at(position[1]) = death;
                map.at(position[0] + 1).at(position[1]) = blank;
            } else {
                map.at(position[0]).at(position[1]) = player;
                map.at(position[0] + 1).at(position[1]) = blank;
            }
        }
    } else {
        cout << "無効なキーです" << endl;
    }
}

void game::play() {
    printMap();
    while (map.at(7).at(7) == goal) {
        move();
        printMap();
        if (map.at(position[0]).at(position[1]) == death) {
            break;
        }
    }
    if (map.at(7).at(7) == player) {
        cout << "クリア!" << endl;
    } else {
        cout << "ゲームオーバー..." << endl;
    }
}

int main() {
    game meiro;
    meiro.makeMap();
    meiro.play();
    return 0;
}
