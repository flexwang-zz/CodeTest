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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** p1 = &head, *p2 = head;
        for (int i=0; i<n; i++)
            p2 = p2->next;
        while (p2) {
            p1 = &(*p1)->next;
            p2 = p2->next;
        }
        
        ListNode* temp = *p1;
        *p1 = temp->next;
        delete temp;
        return head;
    }
};