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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode *p = &head;

        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val > l2->val) {
                    *p = new ListNode(l2->val);
                    l2 = l2->next;
                }
                else {
                    *p = new ListNode(l1->val);
                    l1 = l1->next;
                }
            }
            else if (l1) {
                *p = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                *p = new ListNode(l2->val);
                l2 = l2->next;
            }
            p = &(*p)->next;
        }
        return head;
    }
};