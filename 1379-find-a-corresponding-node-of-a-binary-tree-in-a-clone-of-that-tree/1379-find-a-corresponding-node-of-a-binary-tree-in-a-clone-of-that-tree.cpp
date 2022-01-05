/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &res){
        if(res!=NULL)
            return;
        if(original==target){
            res=cloned;
            return;
        }
        if(original->left){
            helper(original->left, cloned->left, target, res);
        }
        if(original->right){
            helper(original->right, cloned->right, target, res);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res=NULL;
        helper(original, cloned, target, res);
        return res;
    }
};