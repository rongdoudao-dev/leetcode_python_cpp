/*
LeetCode 322. 零钱兑换
难度：中等
算法：动态规划（完全背包）
时间复杂度：O(amount * len(coins))
空间复杂度：O(amount)
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = 凑成金额i所需最少硬币数
        // dp[i] = min(dp[i], dp[i - coin] + 1)
        int max_value = amount + 1;
        vector<int> dp(amount + 1, max_value);
        dp[0] = 0;
        for (int current_amount = 1; current_amount <= amount; current_amount++) {
            for (int coin : coins) {
                if (coin <= current_amount) {
                    dp[current_amount] = min(dp[current_amount], dp[current_amount - coin] + 1);
                }
            }
        }
        return (dp[amount] == max_value) ? -1 : dp[amount];
    }
};
