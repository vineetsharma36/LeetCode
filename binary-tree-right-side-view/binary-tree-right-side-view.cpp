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
    void helper(TreeNode* root, vector<int> &res){
        
        
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n--){
                root=q.front();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                q.pop();
                temp.push_back(root->val);
            }
            res.push_back(temp[temp.size()-1]);
        }
        return res;
    }
};