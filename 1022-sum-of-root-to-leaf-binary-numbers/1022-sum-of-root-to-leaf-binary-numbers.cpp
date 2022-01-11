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
    int dec(vector<int> v){
        int res=0,n=0;
        for(int i=v.size()-1;i>=0;i--){
            //cout<<v[i]<<" ";
            res+=pow(2,n)*v[i];
            n++;
        }
        //cout<<endl;
        return res;
    }
    
    void helper(TreeNode* root, vector<int> &v, int &res){
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            res+=dec(v);
        }
        if(root->left){
            helper(root->left, v, res);
        }
        if(root->right){
            helper(root->right, v, res);
        }
        v.resize(v.size()-1);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<int> v;
        int res=0;
        helper(root, v, res);
        return res;
    }
};