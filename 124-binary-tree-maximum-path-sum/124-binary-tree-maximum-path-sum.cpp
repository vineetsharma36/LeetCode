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
    int helper(TreeNode* root, int &res){
        if(root==NULL)
            return 0;
        int ls=max(0,helper(root->left, res));
        int rs=max(0,helper(root->right, res));
        res=max(res, ls+rs+root->val);
        return root->val+ max(ls,rs);
    }
    
    int maxPathSum(TreeNode* root) {        
        int res=INT_MIN;
        helper(root, res);
        return res;
    }
};