
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > > que;
        
        for (int i=0; i<lists.size(); i++)
            if (lists[i])
                que.push(make_pair(lists[i]->val, lists[i]));
        
        ListNode* head = NULL;
        ListNode** pt = &head;
        while (!que.empty()) {
            pair<int, ListNode*>  p = que.top();
            que.pop();
            *pt = new ListNode(p.first);
            pt = &(*pt)->next;
            if (p.second->next)
                que.push(make_pair(p.second->next->val, p.second->next));
        }
        
        return head;
    }
};