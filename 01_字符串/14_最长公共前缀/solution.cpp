/*
LeetCode 14. 最长公共前缀
难度：简单
算法：纵向扫描
时间复杂度：O(mn)，m=字符串平均长度，n=字符串数量
空间复杂度：O(1)
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 纵向扫描：逐列比较所有字符串的第i个字符
        if (strs.empty()) {
            return "";
        }
        for (int index = 0; index < strs[0].size(); index++) {
            char current_char = strs[0][index];
            for (int i = 1; i < strs.size(); i++) {
                if (index == strs[i].size() || strs[i][index] != current_char) {
                    return strs[0].substr(0, index);
                }
            }
        }
        return strs[0];
    }
};
