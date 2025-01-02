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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ret;

        queue<TreeNode*>q;
        if(root)
            q.push(root);

        while(q.size()){
            queue<TreeNode*>qq;
            ret.push_back(q.back()->val);
            while(q.size()){
                auto tp = q.front();
                q.pop();

                if(tp->left)
                    qq.push(tp->left);
                if(tp->right)
                    qq.push(tp->right);

            }
            q =qq;
        }
        return ret;
    }
};