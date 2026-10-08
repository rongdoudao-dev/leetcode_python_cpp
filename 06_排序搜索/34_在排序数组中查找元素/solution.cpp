/*
LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置
难度：中等
算法：两次二分查找（左边界 + 右边界）
时间复杂度：O(log n)
空间复杂度：O(1)
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 找左边界：第一个 >= target
        // 找右边界：第一个 > target，再减1
        int left_bound = findLeftBound(nums, target);
        if (left_bound == nums.size() || nums[left_bound] != target) {
            return {-1, -1};
        }
        int right_bound = findRightBound(nums, target) - 1;
        return {left_bound, right_bound};
    }

private:
    int findLeftBound(vector<int>& nums, int target) {
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

    int findRightBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
