#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    if(t == 10) {
        if (n == 1) cout << -1;
        else {
            cout << 1;
            for (int i = 1; i < n; ++i) cout << 0;
        }
    }
    else {
        cout << t;
        for (int i = 1; i < n; ++i) cout << 0;
    }
    return 0;
}