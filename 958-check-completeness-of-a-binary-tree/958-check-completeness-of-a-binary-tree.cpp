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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                root=q.front();
                q.pop();
                if(root->right && root->left==NULL)
                    return false;
                if((root->left && (root->left->left || root->left->right)) && root->right==NULL)
                    return false;
                if(root->left){
                    if(flag)
                        return false;
                    q.push(root->left);
                }
                if(root->right){
                    if(flag)
                        return false;
                    q.push(root->right);
                }
                if(root->left==NULL || root->right==NULL)
                    flag=true;
            }
        }
        return true;
    }
};