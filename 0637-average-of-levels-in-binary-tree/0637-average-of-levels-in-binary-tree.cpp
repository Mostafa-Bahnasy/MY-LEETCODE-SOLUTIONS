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
    vector<double> averageOfLevels(TreeNode* root) {
        int cnt [10005] = {};
        double avg[10005] ={};

        auto dfs = [&](auto&self,TreeNode*node,int lvl = 0)->void{
            if(node==nullptr)return;
            self(self,node->left,lvl+1);
            self(self,node->right,lvl+1);
            cnt[lvl]++;
            avg[lvl]+=node->val;
        };
        dfs(dfs,root);
        vector<double>ret;
        for(int i = 0;i<10004;i++){
            if(cnt[i]){
                ret.push_back(avg[i]/(1.0*cnt[i]));
            }
        }
        return ret;
    }
};