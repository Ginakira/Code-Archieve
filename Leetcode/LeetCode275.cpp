// LeetCode 275 H指数II
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


// 二分
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};