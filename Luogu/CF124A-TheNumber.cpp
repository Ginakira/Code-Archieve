#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    cin >> n >> a >> b;
    cout << min(n - a, b + 1);
    return 0;
}