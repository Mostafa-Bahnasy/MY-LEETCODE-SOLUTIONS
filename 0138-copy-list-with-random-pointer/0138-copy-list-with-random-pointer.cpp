/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * it = head;
        unordered_map<Node*,Node*>mp;

        while(it){
            mp[it] = new Node(it->val);
            it = it->next;
        }

        it = head;
        
        while(it){
            mp[it]->next = mp[it->next];
            mp[it]->random = mp[it->random];

            it = it->next;
        }
        return mp[head];
    }
};