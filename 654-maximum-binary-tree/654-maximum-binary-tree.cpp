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
    int maxi(vector<int>& nums, int l, int r){
        int res=l;
        for(int i=l+1;i<r;i++){
            if(nums[i]>nums[res]){
                res=i;
            }
        }
        return res;
    }
    
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l==r)
            return NULL;
        int i=maxi(nums, l, r);
        TreeNode* root=new TreeNode(nums[i]);
        root->left=helper(nums, l, i);
        root->right=helper(nums, i+1, r);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};