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
        ListNode* node = NULL;
        ListNode**pt = &node;
        
        ListNode *pre = NULL;
        
        while (head) {
            if ((!pre || pre->val!= head->val) && (!head->next || head->val!=head->next->val)) {
                *pt = new ListNode(head->val);
                pt = &(*pt)->next;
            }
            pre = head;
            head = head->next;
        }
        
        return node;
    }
};