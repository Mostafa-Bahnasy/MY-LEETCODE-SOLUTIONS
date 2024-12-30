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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* it = head;
        int idx = 1;
        while(idx<left)it = it->next,idx++;
        stack<int>st;
        ListNode *L = it;
        while(idx<=right){
            st.push(it->val);
            it = it->next;
            idx++;
        }

        while(st.size()){
            L->val = st.top();
            st.pop();
            L = L->next;
        }

        return head;


    }
};