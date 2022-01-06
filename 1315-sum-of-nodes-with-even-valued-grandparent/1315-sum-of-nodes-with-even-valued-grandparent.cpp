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
        if(root->left){
            if(root->val%2==0)
            {
                if(root->left->left)
                    res+=root->left->left->val;
                if(root->left->right)
                    res+=root->left->right->val;
            } 
            helper(root->left, res);
        }
        if(root->right){
            if(root->val%2==0){
                if(root->right->left)
                    res+=root->right->left->val;
                if(root->right->right)
                    res+=root->right->right->val;
            }
            helper(root->right, res);
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=0;
        helper(root, res);
        return res;
    }
};