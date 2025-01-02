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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        // if(!root)reutrn {};

        deque<TreeNode*>q;
        if(root)
            q.push_back(root);

        for(int i = 0;q.size();i++){
            if(i%2==0){
                vector<int>v;
                for(int j = 0;j<q.size();j++){
                    v.push_back(q[j]->val);
                }
                ret.push_back(v);
            }else{
                vector<int>v;
                for(int j = 0;j<q.size();j++){
                    v.push_back(q[q.size()-j-1]->val);
                }
                ret.push_back(v);
            }

            deque<TreeNode*>qq;
            while(q.size()){
                auto tp = q.front();
                q.pop_front();

                if(tp->left){
                    qq.push_back(tp->left);
                }

                if(tp->right){
                    qq.push_back(tp->right);
                }
            }
            q = qq;
        }
        return ret;
    }
};