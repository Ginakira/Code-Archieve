/************************************************************
    File Name : #222- 练习题1：线段树模板(一).cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/06 22:35:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 10000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)

struct Node {
    int sum;
} tree[(MAX_N << 2) + 5];
int arr[MAX_N + 5];
int root = 1;

void UP(int ind) {
    tree[ind].sum = max(tree[lc(ind)].sum, tree[rc(ind)].sum);
    return;
}

void build(int ind, int l, int r) {
    if (l == r) {
        tree[ind].sum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
}

void modify(int ind, int x, int y, int l, int r) {
    if (l == r) {
        tree[ind].sum = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        modify(lc(ind), x, y, l, mid);
    else
        modify(rc(ind), x, y, mid + 1, r);
    UP(ind);
    return;
}

int query(int ind, int x, int y, int l, int r) {
    if (x <= l && y >= r) {
        return tree[ind].sum;
    }
    int ans = 0x80000000, mid = (l + r) >> 1;
    if (x <= mid) ans = max(ans, query(lc(ind), x, y, l, mid));
    if (y > mid) ans = max(ans, query(rc(ind), x, y, mid + 1, r));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    build(root, 1, n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            modify(root, b, c, 1, n);
        } else {
            cout << query(root, b, c, 1, n) << endl;
        }
    }
    return 0;
}