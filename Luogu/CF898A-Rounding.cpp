#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n % 10 > 5) n += 10 - n % 10;
    else n -= n % 10;
    cout << n;
    return 0;
}