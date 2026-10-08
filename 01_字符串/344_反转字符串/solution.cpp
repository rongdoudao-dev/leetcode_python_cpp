/*
LeetCode 344. 反转字符串
难度：简单
算法：双指针
时间复杂度：O(n)
空间复杂度：O(1)
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // 双指针：left从左往右，right从右往左，交换元素
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
