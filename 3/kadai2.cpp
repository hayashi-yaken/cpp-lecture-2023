#include <iostream>
#include <string>
using namespace std;

string inputStr(string &str) {
    cin >> str;
    return str;
}

int countStr(string str) { return str.length(); }

int main() {
    string letters;
    char target;
    int n = 0;
    cout << "文章を入力してください" << endl;
    inputStr(letters);
    cout << letters << "から何を探しますか" << endl;
    cin >> target;
    const char *change_letters = letters.c_str();
    for (int i = 0; i < countStr(letters); i++) {
        if (change_letters[i] == target) {
            n++;
        }
    }
    cout << letters << "の中に " << target << " は" << endl;
    cout << n << "個あります" << endl;

    return 0;
}
