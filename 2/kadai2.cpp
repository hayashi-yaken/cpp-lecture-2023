#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N;
    int ans = 0;
    cout << "整数の値を入力してください : ";
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cout << i + 1 << "番目の数値: ";
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((a[i] + a[j]) % 2 == 1) {
                ans++;
            }
        }
    }
    cout << "和が奇数になるペアの数は" << ans << "個です" << endl;
}
