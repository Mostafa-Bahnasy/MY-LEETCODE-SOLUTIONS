/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* cur = new ListNode();
        ListNode *ret = cur;
        int carry = 0;
        while(l1 or l2 or carry){
            int nw = carry;
            if(l1)nw+=l1->val,l1=l1->next;
            if(l2)nw+=l2->val,l2=l2->next;
            
            carry = nw/10;
            nw = nw%10;
            cur->next = new ListNode(nw);
            cur = cur->next;
        }
        ret = ret->next;
        return ret;
    }
};