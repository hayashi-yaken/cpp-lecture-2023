#include <time.h>

#include <iomanip>
#include <iostream>
#include <vector>
#define N 10
using namespace std;

int randomNum(int num) { return rand() % num; };

class sortClass {
   private:
    vector<int> array;
    vector<int> copyArray;
    int l;
    int r;
    int pivot;

   public:
    sortClass();
    void init();
    void printArray();
    void swap(int &a, int &b);
    void bubbleSort();
    void quickSort(int L, int R);
    void action();
};

sortClass::sortClass() {
    srand((unsigned int)time(NULL));
    array = vector<int>(N, 0);
    copyArray = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        int num;
        num = randomNum(101);
        array.at(i) = num;
        copyArray.at(i) = num;
    }
    l = 0;
    r = N - 1;
    // 切り捨て除算の明示的表現
    pivot = array.at(int(N / 2));
}

void sortClass::init() {
    for (int i = 0; i < N; i++) {
        copyArray.at(i) = array.at(i);
    }
}

void sortClass::printArray() {
    for (int i = 0; i < N; i++) {
        cout << copyArray.at(i) << ", ";
    }
    cout << endl;
}

void sortClass::swap(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}

void sortClass::bubbleSort() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (copyArray.at(j) > copyArray.at(j + 1)) {
                swap(copyArray.at(j), copyArray.at(j + 1));
            }
        }
    }
};

void sortClass::quickSort(int L, int R) {
    l = L;
    r = R;
    // 切り捨て除算の明示的表現
    pivot = copyArray.at(int((L + R) / 2));
    while (1) {
        if (l > r) break;
        while (copyArray.at(l) < pivot) l++;
        while (copyArray.at(r) > pivot) r--;
        if (l > r) break;
        if (l < r) {
            swap(copyArray.at(l), copyArray.at(r));
        }
        l++;
        r--;
    }
    if (L < r) {
        quickSort(L, r);
    }
    if (l < R) {
        quickSort(l, R);
    }
}

void sortClass::action() {
    cout << "ソート前の配列" << endl;
    printArray();
    cout << endl << "バブルソートによるソート" << endl;
    clock_t start1 = clock();
    bubbleSort();
    clock_t end1 = clock();
    printArray();
    double time1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "ソートにかかった時間 : " << time1 << "s" << endl;
    init();
    cout << endl << "クイックソートによるソート" << endl;
    clock_t start2 = clock();
    quickSort(l, r);
    clock_t end2 = clock();
    printArray();
    double time2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "ソートにかかった時間 : " << time2 << "s" << endl;
}

int main() {
    sortClass data;
    data.action();
    return 0;
}
