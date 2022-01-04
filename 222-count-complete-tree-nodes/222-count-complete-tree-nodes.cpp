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
    void helper(TreeNode* root, int &res){
        res++;
        if(root->left){
            helper(root->left, res);
        }
        if(root->right){
            helper(root->right, res);
        }
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=0;
        helper(root,res);
        return res;
    }
};