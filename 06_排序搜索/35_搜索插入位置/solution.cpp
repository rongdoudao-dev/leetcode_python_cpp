/*
LeetCode 35. 搜索插入位置
难度：简单
算法：二分查找
时间复杂度：O(log n)
空间复杂度：O(1)
*/
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 二分查找：找第一个 >= target 的位置
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
