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
    void helper(TreeNode* root, map<int, map<int, vector<int>>> &mp, int row, int col){
        if(root){
            mp[col][row].push_back(root->val);
        }
        if(root->left){
            helper(root->left, mp, row+1, col-1);
        }
        if(root->right){
            helper(root->right, mp, row+1, col+1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, map<int, vector<int>>> mp;
        helper(root, mp, 0, 0);
        for(auto& x:mp){
            vector<int> v;
            for(auto& y: x.second){
                vector<int> temp = y.second;
                sort(temp.begin(), temp.end());
                v.insert(std::end(v), std::begin(temp), std::end(temp));
            }
            res.push_back(v);
        }
        return res;
    }
};