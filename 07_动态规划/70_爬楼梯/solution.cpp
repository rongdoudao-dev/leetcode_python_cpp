/*
LeetCode 70. 爬楼梯
难度：简单
算法：动态规划（斐波那契数列）
时间复杂度：O(n)
空间复杂度：O(1) 滚动数组优化
*/
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // dp[i] = dp[i-1] + dp[i-2]，用滚动数组优化空间
        if (n <= 2) {
            return n;
        }
        int prev_two = 1;
        int prev_one = 2;
        for (int i = 3; i <= n; i++) {
            int current = prev_one + prev_two;
            prev_two = prev_one;
            prev_one = current;
        }
        return prev_one;
    }
};
