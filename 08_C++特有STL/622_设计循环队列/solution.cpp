/*
LeetCode 622. 设计循环队列
难度：中等
算法：数组 + 双指针（head/tail）
时间复杂度：所有操作 O(1)
空间复杂度：O(k)
*/
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    int capacity;
    vector<int> queue;
    int head;
    int tail;

public:
    MyCircularQueue(int k) {
        // 留一个空位区分空和满
        capacity = k + 1;
        queue.resize(capacity);
        head = 0;
        tail = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        queue[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % capacity;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[(tail - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return head == tail;
    }

    bool isFull() {
        return (tail + 1) % capacity == head;
    }
};
