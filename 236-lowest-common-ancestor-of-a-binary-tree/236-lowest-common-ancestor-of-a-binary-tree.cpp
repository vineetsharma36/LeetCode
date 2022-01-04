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
    void helper(TreeNode* root, TreeNode* x, vector<TreeNode*> &v)
    {
        if(v.size()>0 && v[v.size()-1]==x)
            return;
        v.push_back(root); 
        if(root==x)
            return;
        if(root->left){
            helper(root->left, x, v);
        }
        if(root->right){
            helper(root->right, x, v);
        }
        if(v[v.size()-1]!=x)
            v.resize(v.size()-1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        helper(root, p, v1);
        helper(root, q, v2);
        int z=min(v1.size(),v2.size());
        for(int i=z-1;i>=0;i--){
            if(v1[i]==v2[i])
                return v1[i];
        }
        return p;
    }
};