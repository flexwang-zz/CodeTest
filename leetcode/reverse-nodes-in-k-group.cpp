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
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* node, *pre = NULL;
         ListNode* l = NULL, *head2;
         ListNode**pt = &l, **tail=NULL;
         int i = 0;
         while (head) {

             node = new ListNode(head->val);
             node->next = pre;
             pre = node;
             if (i%k == 0) {
                 tail = &(node->next);
                 head2 = head;
             }
             if (++i % k == 0) {
                 *pt = node;
                 pt = tail;
                 pre = NULL;
             }

             head = head->next;
         }

         if (i%k != 0)
             *pt = head2;

         return l;
     }
};