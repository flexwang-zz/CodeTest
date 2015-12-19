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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //if (!head) return head;
        ListNode **p = &head;
        for (int i=1; i<m; i++)
            p = &(*p)->next;
        ListNode *tail = *p;
        for (int i=m; i<n; i++) {
            ListNode* temp = tail->next;
            tail->next = tail->next->next;
            temp->next = *p;
            *p = temp;
        }
        return head;
    }
};