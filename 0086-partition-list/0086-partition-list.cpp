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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode *low = new ListNode();
        ListNode *high = new ListNode();
        auto low_head = low;
        auto high_head = high;
        auto ptr = head;
        while(ptr){
            if(ptr->val<x){
                low->next = ptr;
                low= low->next;
            }else{
                high->next = ptr;
                high = high->next;
            }
            ptr = ptr->next;
        }
        
        high->next  = nullptr;
        low->next = high_head->next;
        return low_head->next;
    }
};