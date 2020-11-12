// 122. 买卖股票的最佳时机 II
#include <vector>
using std::vector;

// 贪心法 如果今天的价格比明天的价格低 那么就在今天买入 明天卖出
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) {
                maxProfit += diff;
            }
        }
        return maxProfit;
    }
};