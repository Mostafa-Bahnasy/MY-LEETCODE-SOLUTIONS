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
    TreeNode* reverseOddLevels(TreeNode* root) {
        auto dfs = [&](auto&self,TreeNode* left,TreeNode*right,int lvl = 0)->void{
            if(left==nullptr or right == nullptr){
                return;
            }

            if(lvl%2==0){
                swap(left->val,right->val);
            }

            self(self,left->left,right->right,lvl+1);
            self(self,left->right,right->left,lvl+1);
        };
        dfs(dfs,root->left,root->right);
        return root;
    }
};