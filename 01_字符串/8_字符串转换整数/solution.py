"""
LeetCode 8. 字符串转换整数 (atoi)
难度：中等
算法：状态机/直接模拟
时间复杂度：O(n)
空间复杂度：O(1)
"""


class Solution:
    def myAtoi(self, s: str) -> int:
        """
        步骤：1.跳过空格 2.判断符号 3.读取数字 4.处理溢出
        """
        INT_MAX: int = 2**31 - 1
        INT_MIN: int = -(2**31)
        index: int = 0
        sign: int = 1
        result: int = 0
        length: int = len(s)

        # 1. 跳过前导空格
        while index < length and s[index] == ' ':
            index += 1

        # 2. 判断符号
        if index < length and s[index] in '+-':
            sign = -1 if s[index] == '-' else 1
            index += 1

        # 3. 读取数字
        while index < length and s[index].isdigit():
            digit: int = int(s[index])
            # 4. 溢出检查
            if result > (INT_MAX - digit) // 10:
                return INT_MAX if sign == 1 else INT_MIN
            result = result * 10 + digit
            index += 1

        return sign * result
