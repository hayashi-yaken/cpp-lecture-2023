#include <iostream>
#include <string>
using namespace std;

class player {
   public:
    string name;
    int HP;
    int ATK;
    player();
    void attack(player &a);
};

class gameManager {
   public:
    player generatePlayer();
    void start();
    void battle(player &a, player &b);
    void finish(player a, player b);
};

player::player() {
    cout << "名前を入力してください ";
    cin >> name;
    cout << "HPを入力してください ";
    cin >> HP;
    ATK = 20;
}

player gameManager::generatePlayer() {
    player a;
    return a;
}

void player::attack(player &a) {
    a.HP -= ATK;
    cout << a.name << "に" << ATK << "のダメージ!" << endl;
}

void gameManager::start() { cout << "ゲームスタート!" << endl; }

void gameManager::battle(player &a, player &b) {
    while (a.HP > 0 && b.HP > 0) {
        a.attack(b);
        if (b.HP <= 0) {
            break;
        }
        b.attack(a);
    }
}

void gameManager::finish(player a, player b) {
    if (a.HP <= 0) {
        cout << b.name << "の勝利です!" << endl;
    } else {
        cout << a.name << "の勝利です!" << endl;
    }
}

int main() {
    gameManager game;
    player me = game.generatePlayer();
    player enemy = game.generatePlayer();
    game.start();
    game.battle(me, enemy);
    game.finish(me, enemy);
    return 0;
}
