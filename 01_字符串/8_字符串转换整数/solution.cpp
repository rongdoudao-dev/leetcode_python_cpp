/*
LeetCode 8. 字符串转换整数 (atoi)
难度：中等
算法：直接模拟
时间复杂度：O(n)
空间复杂度：O(1)
*/
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // 步骤：1.跳过空格 2.判断符号 3.读取数字 4.处理溢出
        const int INT_MAX_VALUE = INT_MAX;
        const int INT_MIN_VALUE = INT_MIN;
        int index = 0;
        int sign = 1;
        long long result = 0;
        int length = s.size();

        // 1. 跳过前导空格
        while (index < length && s[index] == ' ') {
            index++;
        }

        // 2. 判断符号
        if (index < length && (s[index] == '+' || s[index] == '-')) {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }

        // 3. 读取数字
        while (index < length && isdigit(s[index])) {
            int digit = s[index] - '0';
            result = result * 10 + digit;
            // 4. 溢出检查
            if (sign == 1 && result > INT_MAX_VALUE) {
                return INT_MAX_VALUE;
            }
            if (sign == -1 && -result < INT_MIN_VALUE) {
                return INT_MIN_VALUE;
            }
            index++;
        }

        return static_cast<int>(sign * result);
    }
};
