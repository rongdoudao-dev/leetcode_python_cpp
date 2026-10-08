/*
LeetCode 3. 无重复字符的最长子串
难度：中等
算法：滑动窗口 + 哈希表
时间复杂度：O(n)
空间复杂度：O(min(m, n))
*/
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口：[left, right]，哈希表记录字符最后出现位置
        unordered_map<char, int> char_last_index;
        int max_length = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (char_last_index.count(c) && char_last_index[c] >= left) {
                left = char_last_index[c] + 1;
            }
            char_last_index[c] = right;
            int current_length = right - left + 1;
            max_length = max(max_length, current_length);
        }
        return max_length;
    }
};
