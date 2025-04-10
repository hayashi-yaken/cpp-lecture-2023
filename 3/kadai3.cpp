#include <time.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int randomLineNum(int lineNum) { return rand() % lineNum; };
int randomRowNum(int rowNum) { return rand() % rowNum; };

// 縦線と横線の数を入力する関数
void inputNum(int &lineNum, int &rowNum) {
    cout << "縦線の本数を入力してください : ";
    cin >> lineNum;
    cout << "横線の本数を入力してください : ";
    cin >> rowNum;
}

// 開始位置を入力する関数
void inputStartNum(int &startNum) {
    cout << "スタート位置を選んでください : ";
    cin >> startNum;
}

// あみだくじの番号を表示する関数
void displayNum(int lineNum) {
    for (int i = 0; i < lineNum; i++) {
        if (i + 1 == lineNum) {
            cout << i + 1 << " " << endl;
        } else {
            cout << i + 1 << " ";
        }
    }
}

// 横線をランダムに生成する関数
void makeRandomRow(vector<vector<int> > &randomRowArray, int lineNum,
                   int rowNum) {
    // 初期化処理
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < lineNum - 1; j++) {
            randomRowArray.at(i).at(j) = 0;
        }
    }
    for (int i = 0; i < rowNum; i++) {
        bool flag = false;
        while (flag == false) {
            int r = randomRowNum(rowNum);
            int l = randomLineNum(lineNum - 1);
            if (randomRowArray.at(r).at(l) != 1) {
                if (l == 0) {
                    if (randomRowArray.at(r).at(l + 1) != 1) {
                        randomRowArray.at(r).at(l) = 1;
                        flag = true;
                    }
                } else if (l == lineNum - 1) {
                    if (randomRowArray.at(r).at(l - 1) != 1) {
                        randomRowArray.at(r).at(l) = 1;
                        flag = true;
                    }
                } else {
                    if (randomRowArray.at(r).at(l - 1) != 1 &&
                        randomRowArray.at(r).at(l + 1) != 1) {
                        randomRowArray.at(r).at(l) = 1;
                        flag = true;
                    }
                }
            }
        }
    }
}

// 横線の位置を表示する関数(管理者用)
void printRandomRow(vector<vector<int> > &randomRowArray, int lineNum,
                    int rowNum) {
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < lineNum - 1; j++) {
            cout << randomRowArray.at(i).at(j);
        }
        cout << endl;
    }
}

// あみだくじを生成する関数
void makeAmida(vector<vector<int> > &randomRowArray,
               vector<vector<string> > &amidaArray, int lineNum, int rowNum) {
    for (int i = 0; i < rowNum * 2 + 1; i++) {
        for (int j = 0; j < lineNum * 2 - 1; j++) {
            if (i % 2 == 1) {
                if (j % 2 == 1) {
                    if (randomRowArray.at((i - 1) / 2).at((j - 1) / 2) == 1) {
                        amidaArray.at(i).at(j) = "-";
                    } else {
                        amidaArray.at(i).at(j) = " ";
                    }
                } else {
                    amidaArray.at(i).at(j) = " ";
                }
            } else {
                if (j % 2 == 1) {
                    amidaArray.at(i).at(j) = " ";
                } else {
                    amidaArray.at(i).at(j) = "|";
                }
            }
        }
    }
}

// 目標を生成する関数
void makeTarget(vector<string> &targetArray, int lineNum) {
    int targetNum = randomLineNum(lineNum);
    for (int i = 0; i < lineNum * 2 - 1; i++) {
        if (i == targetNum * 2) {
            targetArray.at(i) = "*";
        } else {
            targetArray.at(i) = " ";
        }
    }
}

// 目標を出力する関数
void printTarget(vector<string> targetArray, int lineNum) {
    for (int i = 0; i < lineNum * 2 - 1; i++) {
        cout << targetArray.at(i);
    }
}

// あみたくじを表示する関数
void printAmida(vector<string> targetArray, vector<vector<string> > amidaArray,
                int lineNum, int rowNum) {
    displayNum(lineNum);
    for (int i = 0; i < rowNum * 2 + 1; i++) {
        for (int j = 0; j < lineNum * 2 - 1; j++) {
            cout << amidaArray.at(i).at(j);
        }
        cout << endl;
    }
    printTarget(targetArray, lineNum);
    cout << endl;
}

// あみだくじを解く関数
void solveAmida(vector<vector<string> > &amidaArray, int lineNum, int rowNum,
                int startNum) {
    int goingNum = startNum;
    for (int i = 0; i < rowNum * 2 + 1; i += 2) {
        // cout << goingNum << endl;
        amidaArray.at(i).at((goingNum * 2) - 2) = ":";
        if (i + 1 == rowNum * 2 + 1) {
            continue;
        } else if (goingNum == 1) {
            if (amidaArray.at(i + 1).at(1) == "-") {
                amidaArray.at(i + 1).at(1) = "…";
                goingNum += 1;
            }
        } else if (goingNum == lineNum) {
            if (amidaArray.at(i + 1).at((lineNum * 2) - 3) == "-") {
                amidaArray.at(i + 1).at((lineNum * 2) - 3) = "…";
                goingNum -= 1;
            }
        } else {
            if (amidaArray.at(i + 1).at((goingNum * 2) - 1) == "-") {
                amidaArray.at(i + 1).at((goingNum * 2) - 1) = "…";
                goingNum += 1;
            } else if (amidaArray.at(i + 1).at((goingNum * 2) - 3) == "-") {
                amidaArray.at(i + 1).at((goingNum * 2) - 3) = "…";
                goingNum -= 1;
            }
        }
    }
}

// 正誤判定を行う関数
void judge(vector<string> targetArray, vector<vector<string> > amidaArray,
           int lineNum, int rowNum) {
    for (int i = 0; i < lineNum * 2 - 1; i++) {
        if (amidaArray.at(rowNum * 2).at(i) == ":") {
            if (targetArray.at(i) == "*") {
                cout << "********** 正解! **********" << endl;
            } else {
                cout << "*** ゲームオーバーだどん... ***" << endl;
            }
        }
    }
}

int main(void) {
    int line, row, start;
    srand((unsigned int)time(NULL));
    inputNum(line, row);
    vector<string> target(line * 2 - 1);
    vector<vector<int> > randomRow(row, vector<int>(line));
    vector<vector<string> > amida(row * 2 + 1, vector<string>(line * 2 - 1));
    makeRandomRow(randomRow, line, row);
    makeAmida(randomRow, amida, line, row);
    makeTarget(target, line);
    printAmida(target, amida, line, row);
    inputStartNum(start);
    solveAmida(amida, line, row, start);
    printAmida(target, amida, line, row);
    judge(target, amida, line, row);

    return 0;
}
