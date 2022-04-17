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
    void inorder(TreeNode* root, vector<int> &res){
        if(root->left)
            inorder(root->left, res);
        res.push_back(root->val);
        if(root->right)
            inorder(root->right, res);
    }
    
    int i=1;
    void create(TreeNode* root, vector<int> &res){
        if(i==res.size())
            return;
        root->right=new TreeNode(res[i++]);
        create(root->right, res);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
            return root;
        vector<int> res;
        inorder(root, res);
        TreeNode* newRoot= new TreeNode(res[0]);
        create(newRoot, res);
        return newRoot;
    }
};