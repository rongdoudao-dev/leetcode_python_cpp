/*
LeetCode 49. 字母异位词分组
难度：中等
算法：哈希表 + 排序键
时间复杂度：O(n * k log k)
空间复杂度：O(n * k)
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 排序后的字符串作为key，异位词排序后相同
        unordered_map<string, vector<string>> anagram_groups;
        for (string& s : strs) {
            string sorted_key = s;
            sort(sorted_key.begin(), sorted_key.end());
            anagram_groups[sorted_key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : anagram_groups) {
            result.push_back(pair.second);
        }
        return result;
    }
};
