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
        if(root->left){
            helper(root->left,res);
        }
        res.push_back(root->val);
        if(root->right){
            helper(root->right,res);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        vector<int> res;
        helper(root, res);
        for(int i=1;i<res.size();i++){
            if(res[i]<=res[i-1])
                return false;
        }
        return true;
    }
};