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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow, *fast;
        
        slow = head;
        fast = head;
        
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            
            if(fast)
            {
                fast = fast->next;
                if( fast == slow)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        
        if( !fast )
        {
            return NULL;
        }
        else
        {
            slow = head;
            
            while( slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            
            return slow;
        }
    }
};