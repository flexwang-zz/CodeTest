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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p1 = head;
        ListNode* new_head, **lastp = &new_head;
        
        while (p1 && p1->next) {
            ListNode* temp = p1->next->next;
            *lastp = p1->next;
            p1->next->next = p1;
            p1->next = temp;
            lastp = &(p1->next);
            p1 = temp;
        }
        
        return new_head;
    }
};