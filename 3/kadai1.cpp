#include <iostream>
using namespace std;

void minutesToHours() {
    int data;
    int hours, minutes;
    cout << "60より大きい値を入力してください" << endl;
    cin >> data;
    if (data >= 60) {
        hours = data / 60;
        minutes = data % 60;
        cout << data << "分は" << hours << "時間" << minutes << "分です"
             << endl;
    } else {
        cout << data << "分です" << endl;
    }
}

int main() {
    minutesToHours();
    return 0;
}
