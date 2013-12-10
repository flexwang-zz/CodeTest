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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* last = NULL;
        ListNode* cur = head;
        while(cur)
        {
            if( last && last->val==cur->val)
            {
                last->next = cur->next;
                delete cur;
                cur = last->next;
            }
            else
            {
                last = cur;
                cur = cur->next;
            }

        }
        
        return head;
    }
};