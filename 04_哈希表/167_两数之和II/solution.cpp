/*
LeetCode 167. 两数之和 II - 输入有序数组
难度：简单
算法：双指针（数组已排序）
时间复杂度：O(n)
空间复杂度：O(1)
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 双指针：left从左，right从右，和小left右移，和大right左移
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int current_sum = numbers[left] + numbers[right];
            if (current_sum == target) {
                return {left + 1, right + 1};
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
