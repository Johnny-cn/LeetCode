/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode(0); //记录两个节点相加的结果
		ListNode* p = tmp;
		while (l1 || l2 ) { //两个表都为空时退出
			p->val = (l1?l1->val:0) + (l2?l2->val:0) + p->val;  //两个节点和等于当前节点的值加上进位
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
			if (l1 || l2 || p->val/10) {  //创建新节点的条件：至少还有节点没有处理，或者出现进位的情况
				p->next = new ListNode(p->val/10);
				if (p->val > 9) p->val %= 10;				//将p的值置位进位数
				p = p->next;
			}
		}
		return tmp;
    }
};