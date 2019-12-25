/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
   ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = new ListNode(0);  //因为头结点包含有效值因此头结点也可能被删除，需要新建一个节点作为头结点，防止头结点被删除
        p->nex t= head; 
        head = p;  //新节点作为结果返回头结点
        ListNode *left,*right;
        while(NULL != p->next) 
        {
            lef t= p->next; //第一个开始比较的节点
            right =left;    
            while(right->next && right->next->val==left->val)  //从left节点开始，直到没有重复节点后退出
                right = right->next;
            if(left == right) //若左右节点相同，证明右边没有重复节点，可以开始下一个节点的比较
				p = p->next;
            else             //否则将当前节点的后继直接移动到右边非重复元素位置
				p->next = right->next;
        }
        return head->next;
    }
};