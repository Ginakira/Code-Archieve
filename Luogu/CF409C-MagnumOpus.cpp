#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << min(a, min(b, min(c / 2, min(d / 7, e / 4))));
    return 0;
}