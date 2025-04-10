#include <iostream>
#include <vector>
#define N 10
using namespace std;

int main(void) {
    vector<int> a(N);
    cout << N << "個の整数を入力してください。" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "番目の数値: ";
        cin >> a[i];
    }
    int max = a[0];
    int min = a[0];
    for (int i = 0; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
        } else if (a[i] < min) {
            min = a[i];
        }
    }
    cout << "最大値は" << max << ",最小値は" << min << "です" << endl;
}
