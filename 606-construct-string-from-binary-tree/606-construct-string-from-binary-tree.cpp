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
    void helper(TreeNode* root, string& res){
        res+='('+to_string(root->val);
        if(root->left){
            helper(root->left, res);
        }
        if(root->right){
            if(!root->left){
                res+="()";
            }
            helper(root->right, res);
        }
        res+=')';
    }
    
    string tree2str(TreeNode* root) {
        string res;
        helper(root, res);
        res=res.substr(1, res.length()-2);
        return res;
    }
};