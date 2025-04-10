#include <iostream>
using namespace std;
int main(void) {
    cout << "国語・英語・数学・理科・社会の点数を入力してください" << endl;
    int japanese, english, math, science, social;
    cin >> japanese >> english >> math >> science >> social;
    int total;
    total = japanese + english + math + science + social;
    cout << "合計点 : " << total << endl;
    cout << "平均点 : " << (double)total / 5 << endl;

    return 0;
}
