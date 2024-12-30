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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto count = [&]()->int{
            auto it = head;
            int cnt = 0;
            while(it)cnt++, it = it->next;
            return cnt - n;
        };

        int pos = count();
        cout<<pos<<"\n";
        if(pos==0)return head->next;

        auto it = head;
        while(it and pos>1)pos--,it= it->next;
        if(it->next->next)
            it->next = it->next->next;
        else
            it->next = NULL;
        return head;
    }
};