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
    void helper(TreeNode* root, vector<vector<int>> &res, vector<int> v, int sum, int targetSum)
    {
        sum+=root->val;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                res.push_back(v);
            }
            sum-=root->val;
            v.resize(v.size()-1);
        }
        if(root->left){
            helper(root->left,res,v,sum,targetSum);
        }
        if(root->right){
            helper(root->right,res,v,sum,targetSum);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        vector<int> v;
        helper(root,res,v,0,targetSum);
        return res;
    }
};