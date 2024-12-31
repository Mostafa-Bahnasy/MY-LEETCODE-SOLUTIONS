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
        while(head){
            if(head->val<x){
                low->next = head;
                low= low->next;
            }else{
                high->next = head;
                high = high->next;
            }
            head = head->next;
        }
        
        high->next  = nullptr;
        low->next = high_head->next;
        return low_head->next;
    }
};