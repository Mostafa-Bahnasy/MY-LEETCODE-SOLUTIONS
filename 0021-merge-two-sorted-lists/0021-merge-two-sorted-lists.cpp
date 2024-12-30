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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* cur = new ListNode();
        ListNode *ret = cur;

        while(l1 and l2){
            if(l1->val < l2->val){
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                // cout<<"H\n";
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while(l1){
            cur->next = new ListNode(l1->val);
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2){
            // cout<<l2->val<<"\n";
            cur->next = new ListNode(l2->val);
            cur = cur->next;

            l2 = l2->next;
        }
        
        ret = ret->next;
        return ret;

    }
};