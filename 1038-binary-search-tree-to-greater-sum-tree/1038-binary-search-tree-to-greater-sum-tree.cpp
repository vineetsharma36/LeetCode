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
    void helper(TreeNode* root, int &v){
        if(root->right){
            helper(root->right, v);
        }
        v+=root->val;
        root->val=v;
        if(root->left){
            helper(root->left, v);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        int sum=0;
        helper(root, sum);
        return root;
    }
};