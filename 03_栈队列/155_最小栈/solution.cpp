/*
LeetCode 155. 最小栈
难度：中等
算法：辅助栈（同步最小值）
时间复杂度：所有操作 O(1)
空间复杂度：O(n)
*/
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<int> main_stack;
    stack<int> min_stack;

public:
    MinStack() {}

    void push(int val) {
        main_stack.push(val);
        int current_min = min_stack.empty() ? val : min(val, min_stack.top());
        min_stack.push(current_min);
    }

    void pop() {
        main_stack.pop();
        min_stack.pop();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};
