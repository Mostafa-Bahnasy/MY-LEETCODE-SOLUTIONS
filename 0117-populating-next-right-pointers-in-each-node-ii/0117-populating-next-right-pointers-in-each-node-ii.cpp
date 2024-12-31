/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>q;

        q.push(root);
        
        while(q.size()){
            queue<Node*>qq ;
            Node* node = NULL;
            while(q.size()){
                auto cur = q.front();
                q.pop();
                if(node)
                    node->next = cur;
                node = cur;
                if(node->left)
                    qq.push(node->left);
                if(node->right)
                    qq.push(node->right);

            }

            node->next = NULL;
            q = qq;
        }
        return root;
    }
};