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
        res.push_back(root->val);
        if(root->left)
            helper(root->left,res);
        if(root->right)
            helper(root->right,res);
    }
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        vector<int> res;
        helper(root, res);
        int i=1;
        while(i<res.size()){
            TreeNode* temp=new TreeNode(res[i]);
            root->left=NULL;
            root->right=temp;
            root=root->right;
            i++;
        }
    }
};