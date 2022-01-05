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
    int helper(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int n=q.size();
            sum=0;
            while(n--){
                root=q.front();
                q.pop();
                sum+=root->val;
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
        }
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        return helper(root);
    }
};