/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (NULL != cur) {
            next = cur ->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};