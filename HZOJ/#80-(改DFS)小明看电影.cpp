/************************************************************
    File Name : #80-小明看电影.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/11 20:41:33
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, sx, sy;
char mmap[505][505];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int func(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int tx = x + dir[i][0], ty = y + dir[i][1];
        if (mmap[tx][ty] == 'g') return 1;
        if (mmap[tx][ty] == '.') {
            mmap[tx][ty] = '*';
            if (func(tx, ty)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') sx = i, sy = j;
        }
    }
    if (func(sx, sy)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}