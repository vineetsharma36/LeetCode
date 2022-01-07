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
        if(root==NULL)
            return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2,res;
        helper(root1, v1);
        helper(root2, v2);
        int i1=0, i2=0;
        while(i1<v1.size() && i2<v2.size()){
            if(v1[i1]<=v2[i2]){
                res.push_back(v1[i1++]);
            }
            else{
                res.push_back(v2[i2++]);
            }
        }
        while(i1<v1.size()){
            res.push_back(v1[i1++]);
        }
        while(i2<v2.size()){
            res.push_back(v2[i2++]);
        }
        return res;
    }
};