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
#define ll long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 1});
        int res=1;
        while(!q.empty()){
            int n=q.size();
            int mn, mx, mm=q.front().second;
            for(int i=0;i<n;i++)
            {
                unsigned long long curr = q.front().second - mm;
                if(i==n-1){
                    mx=q.front().second;
                }
                if(i==0){
                    mn=q.front().second;
                }
                if(q.front().first->left){
                    q.push({q.front().first->left, curr*2});
                }
                if(q.front().first->right){
                    q.push({q.front().first->right, curr*2+1});
                }
                q.pop();
            }
            int t=mx-mn+1;
            res=max(res, t);
        }
        return res;
    }
};