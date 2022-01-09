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
    int maxLevelSum(TreeNode* root) {
        int res=0,mx=INT_MIN,level=0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            level++;
            int n=q.size();
            int sum=0;
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
            if(sum>mx){
                mx=sum;
                res=level;
            }
        }
        return res;
    }
};