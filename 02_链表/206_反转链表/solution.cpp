/*
LeetCode 206. 反转链表
难度：简单
算法：迭代
时间复杂度：O(n)
空间复杂度：O(1)
*/
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 迭代法：三个指针 prev, curr, next_temp
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;
    }
};
