/*
LeetCode 53. 最大子数组和
难度：中等
算法：动态规划（Kadane算法）
时间复杂度：O(n)
空间复杂度：O(1)
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i] = max(nums[i], dp[i-1] + nums[i])
        // 即：要么从当前重新开始，要么接上之前的
        int max_sum = nums[0];
        int current_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};
