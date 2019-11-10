#include <algorithm>
#include <iostream>
using namespace std;

int a[5];

int main() {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3])
        cout << "TRIANGLE";
    else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3])
        cout << "SEGMENT";
    else
        cout << "IMPOSSIBLE";
    return 0;
}