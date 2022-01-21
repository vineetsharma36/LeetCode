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
    void helper(TreeNode* root, vector<TreeNode*> &v){
        if(root==NULL)
            return;
        helper(root->left,v);
        v.push_back(root);
        helper(root->right,v);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        helper(root, v);
        for(int i=0;i<v.size();i++){
            cout<<v[i]->val<<" ";
        }
        bool flag=false;
        int a, b;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[j]->val<v[i]->val)
                {
                    if(!flag){
                        flag=true;
                        a=i;
                        break;
                    }                    
                }
            }
        }
        for(int j=v.size()-1;j>a;j--){
            if(v[j]->val<v[a]->val)
            {
                b=j;
                break;
            }
        }
        int temp;
        temp=v[a]->val;
        v[a]->val=v[b]->val;
        v[b]->val=temp;
    }
};