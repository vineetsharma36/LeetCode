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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> res(2000);
        int level=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            TreeNode* temp=q.front().first;
            int l=q.front().second;
            level=max(level,l);
            res[l].push_back(temp->val);
            q.pop();
            if(temp->left){
                q.push({temp->left,l+1});
            }
            if(temp->right){
                q.push({temp->right,l+1});
            }
        }
        res.resize(level+1);
        return res;
    }
};