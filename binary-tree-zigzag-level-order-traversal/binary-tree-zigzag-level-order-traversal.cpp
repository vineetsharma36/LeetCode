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
    void helper(TreeNode* root, vector<vector<int>> &res){
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n--){
                root=q.front();
                temp.push_back(root->val);
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
                q.pop();
            }
            if(flag){
                int i=0,j=temp.size()-1,p;
                while(i<j){
                    p=temp[j];
                    temp[j]=temp[i];
                    temp[i]=p;
                    i++;
                    j--;
                }
            }
            res.push_back(temp);
            flag=!flag;
        }            
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> res;
        helper(root,res);
        return res;
    }
};