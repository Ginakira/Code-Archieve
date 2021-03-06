/************************************************************
    File Name : #236-递归实现组合型枚举.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/11 19:25:03
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, ans[15], cnt;

void output() {
    for (int i = 0; i < m; ++i) {
        i&& cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return;
}

void func(int s, int left) {
    if (!left) {
        output();
        return;
    }
    for (int i = s; i <= n - left + 1; ++i) {
        ans[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
    return;
}

int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}