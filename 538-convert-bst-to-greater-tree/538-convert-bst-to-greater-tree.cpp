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
    int i=0;
    void convert(TreeNode* root, vector<int> &res){
        if(root->left)
            convert(root->left, res);
        
        root->val=res[i++];

        if(root->right)
            convert(root->right, res);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return root;
        vector<int> res;
        inorder(root, res);
        for(int i=res.size()-2; i>=0;i--)
        {
            res[i]+=res[i+1];
        }
        convert(root, res);
        return root;
    }
};