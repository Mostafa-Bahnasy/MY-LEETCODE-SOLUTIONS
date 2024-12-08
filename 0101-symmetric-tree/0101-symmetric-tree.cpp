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
    bool isSymmetric(TreeNode* root) {
        bool ret = true;
        auto dfs = [&](auto&self,TreeNode*left,TreeNode*right)->void{
            if((left==nullptr&&right!=nullptr )|| (right==nullptr&&left!=nullptr ))return ret=0, void();
            if(left==nullptr)return void();
            if(left->val!=right->val)return ret = 0,void();
            self(self,left->left,right->right);
            self(self,left->right,right->left);
            
        };
        dfs(dfs,root->left,root->right);
        return ret;
    }
};