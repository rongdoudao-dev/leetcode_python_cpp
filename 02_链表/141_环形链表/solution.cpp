/*
LeetCode 141. 环形链表
难度：简单
算法：快慢指针（Floyd判圈算法）
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
    bool hasCycle(ListNode* head) {
        // 快慢指针：slow每次走1步，fast每次走2步，相遇则有环
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
