/*
* 编写一个程序，找到两个单链表相交的起始节点。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//相交问题，利用双指针，考虑路程和速度。
//对于两个链表相交，若速度相同，路程相同，若相交则指针相等
//若两个链表不相等，则用指针将两个链表都走一次，此时两个指针所走过的路程相同。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (NULL == headA || NULL == headB)
				return NULL;
			ListNode* pA = headA;
			ListNode* pB = headB;
			//速度相同，若长度也相同，则指针相同时有两种情况，1.相交。2.为空
			while (pA != pB) {
				pA = (NULL == pA) ? headB : pA->next;
				pB = (NULL == pB) ? headA : pB->next;
			}
			return pA;
	}
};