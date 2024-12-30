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
    ListNode* deleteDuplicates(ListNode* head) {
        auto it = head;

        while(it){
            auto itt = it->next;
            bool del = false;
            while(itt and it->val == itt->val)itt = itt->next,del = true;
            it->next =  itt;
            if(del and it)
                it->val = 200;
            it = it->next;
        }

        while(head and head->val == 200)head = head->next;

        it = head;
        while(it){
            while(it->next and it->next->val == 200) it->next = it->next->next;
            // cout<<it->val<<" ";
            it= it->next;
        }
        return head;
    }
};