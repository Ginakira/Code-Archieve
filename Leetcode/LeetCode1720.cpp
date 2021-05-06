// LeetCode 1720 编码异或后的数组
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        vector<int> result(n);
        result[0] = first;
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] ^ encoded[i - 1];
        }
        return result;
    }
};