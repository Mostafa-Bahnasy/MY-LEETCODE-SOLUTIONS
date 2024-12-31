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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        auto count =[&]()->int{
            auto ptr = head;
            int ret = 0;
            while(ptr){
                ptr = ptr->next;
                ret++;
            }
            return ret;
        };

        int sz = count();
        k%=sz;
        auto ptr = head;
        while(ptr->next){
            ptr = ptr->next;
        }

        ptr->next = head;
        auto it = head;
        for(int i = 0;i<sz-k-1;i++){
            it = it->next;
        }

        auto ret = it->next;
        it->next = NULL;

        return ret;
    }
};