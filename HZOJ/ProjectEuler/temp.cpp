/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/29 20:03:41
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 4000000

int prime[MAX_N + 5] = {0};
int f[MAX_N + 5] = {0};
int cnt[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 1 + i;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[prime[j] * i] = f[i] / (pow(prime[j], cnt[i] + 1) - 1) *
                                  (pow(prime[j], cnt[i] + 2) - 1);
                cnt[prime[j] * i] = cnt[i] + 1;
                break;
            } else {
                f[prime[j] * i] = f[i] * f[prime[j]];
                cnt[prime[j] * i] = 1;
            }
        }
    }
}

void init2() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = i + 1;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (pow(prime[j], cnt[i] + 1) - 1) *
                                  (pow(prime[j], cnt[i] + 2) - 1);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {  //互素
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
    return;
}

int main() {
    init();
    long long sum = 0;
    for (int i = 2; i < MAX_N; ++i) f[i] -= i;
    for (int i = 2; i < MAX_N; ++i) {
        if (f[i] != i && f[i] <= MAX_N && i == f[f[i]]) sum += i;
    }
    cout << sum << endl;
    return 0;
}