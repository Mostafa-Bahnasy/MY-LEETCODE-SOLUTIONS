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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        auto solve =[&](ListNode *it)->void{
            stack<int>st;
            ListNode* itt = it;
            while(it){
                if(st.size()==k)break;
                st.push(it->val);
                it= it->next;
            }
            // cout<<it->val<<" \n";
            if(st.size()<k)return;

            while(st.size()){
                itt->val = st.top();
                st.pop();
                itt = itt->next;
            }
            // cout<<it->val<<" \n";

        };
        ListNode* it = head;
        // int cnt = 10;
        while(it){
            ListNode* tmp = it;
            solve(tmp);
            int kk = k;
            while(it and kk--)it = it->next;
            // cnt--;
            // cout<<it->val<<"\n\n";
        }

        return head;
    }
};