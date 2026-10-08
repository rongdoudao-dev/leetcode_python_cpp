/*
LeetCode 232. 用栈实现队列
难度：简单
算法：双栈（输入栈 + 输出栈）
时间复杂度：push O(1)，pop 均摊 O(1)
空间复杂度：O(n)
*/
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input_stack;
    stack<int> output_stack;

    void move_input_to_output() {
        // 输出栈为空时，把输入栈全部倒入输出栈
        if (output_stack.empty()) {
            while (!input_stack.empty()) {
                output_stack.push(input_stack.top());
                input_stack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        input_stack.push(x);
    }

    int pop() {
        move_input_to_output();
        int result = output_stack.top();
        output_stack.pop();
        return result;
    }

    int peek() {
        move_input_to_output();
        return output_stack.top();
    }

    bool empty() {
        return input_stack.empty() && output_stack.empty();
    }
};
