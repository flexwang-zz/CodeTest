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
        ListNode* head = NULL;
        int carry = 0;
        ListNode** p = &head;
        
        while (l1 || l2) {
            if (l1 && l2) {
                int val = l1->val+l2->val+carry;
                *p = new ListNode(val%10);
                carry = val/10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1) {
                int val = l1->val + carry;
                *p = new ListNode(val%10);
                carry = val/10;
                l1 = l1->next;
            }
            else {
                int val = l2->val + carry;
                *p = new ListNode(val%10);
                carry = val/10;
                l2 = l2->next;
            }
            p = &(*p)->next;
        }
        if (carry) *p = new ListNode(carry);
        return head;
    }
};