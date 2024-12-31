/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root )return ;
        TreeNode * ret = new TreeNode();
        TreeNode* head = ret;
        auto dfs =[&](auto&self,TreeNode*node)->void{
            if(node == NULL)return;
            cout<<"N: "<<node->val<<"\n";
            ret->right = new TreeNode(node->val);
            ret = ret->right;
            // cout<<ret->val<<"\n";
            self(self,node->left);
            self(self,node->right);
            
        };

        dfs(dfs,root);
        
        head = head->right;
        auto ptr = root;
        while(head){
            ptr->left = NULL;
            ptr->val = head->val;
            
            ptr->right = head->right;
            ptr = ptr->right;
            head = head->right;
        }
        
        // cout<<root->right->right->right->right->val<<"\n";
    }
};