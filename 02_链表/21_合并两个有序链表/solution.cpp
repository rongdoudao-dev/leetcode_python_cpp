/*
LeetCode 21. 合并两个有序链表
难度：简单
算法：虚拟头节点 + 双指针
时间复杂度：O(n+m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 虚拟头节点 dummy，比较两个链表当前节点值，小的接在后面
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        current->next = (list1 != nullptr) ? list1 : list2;
        return dummy->next;
    }
};
