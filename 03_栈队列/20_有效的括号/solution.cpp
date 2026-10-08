/*
LeetCode 20. 有效的括号
难度：简单
算法：栈
时间复杂度：O(n)
空间复杂度：O(n)
*/
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 栈：左括号入栈，右括号匹配栈顶
        stack<char> char_stack;
        unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};
        for (char c : s) {
            if (mapping.count(c)) {
                char top_element = char_stack.empty() ? '#' : char_stack.top();
                if (!char_stack.empty()) char_stack.pop();
                if (mapping[c] != top_element) {
                    return false;
                }
            } else {
                char_stack.push(c);
            }
        }
        return char_stack.empty();
    }
};
