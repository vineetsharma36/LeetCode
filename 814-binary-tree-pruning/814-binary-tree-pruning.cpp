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
    bool helper(TreeNode* root){
        if(root==NULL)
            return false;
        bool leftsubtree=helper(root->left);
        if(!leftsubtree)
            root->left=NULL;
        bool rightsubtree=helper(root->right);
        if(!rightsubtree)
            root->right=NULL;
        if(root->val==1 || leftsubtree || rightsubtree){
            return true;
        }
        return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
            return root;
        return helper(root)?root:NULL;
    }
};