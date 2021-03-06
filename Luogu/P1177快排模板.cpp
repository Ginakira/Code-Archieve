#include <iostream>
using namespace std;

void quickSort(int *arr, int left, int right) {
    int i = left, j = right;
    int mid = arr[(i + j) / 2];
    while(i <= j) {
        while(arr[i] < mid) i++;
        while(arr[j] > mid) j--;
        if(i <= j) {
            int tmp;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if(i < right) quickSort(arr, i, right);
    if(left < j) quickSort(arr, left, j);
}

int num[100001];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> num[i];
    quickSort(num, 0, n - 1);
    for(int i = 0; i < n; ++i) cout << num[i] << ' ';
    return 0;
}