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
    bool check(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root=q.front();
            int n=q.size();
            vector<int> temp;
            while(n--){
                root=q.front();
                if(root==NULL){
                    temp.push_back(1031);
                    q.pop();
                    continue;
                }
                else{
                    temp.push_back(root->val);
                }
                q.push(root->left);
                q.push(root->right);
                
                q.pop();
            }
            int i=0,j=temp.size()-1;
            while(i<j){
                if(temp[i]!=temp[j])
                    return false;
                i++;
                j--;
            }
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return check(root);
    }
};