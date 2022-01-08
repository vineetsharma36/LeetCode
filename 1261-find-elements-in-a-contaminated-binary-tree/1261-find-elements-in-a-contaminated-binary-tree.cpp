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
class FindElements {
public:
    TreeNode* t;
    unordered_set<int> s;
    void helper(TreeNode* root, int z){
        if(root==NULL)
            return;
        root->val=z;
        s.insert(z);
        if(root->left){
            helper(root->left, 2*z+1);
        }
        if(root->right){
            helper(root->right, 2*z+2);
        }
    }
    
    FindElements(TreeNode* root) {
        t=root;
        int z=0;
        helper(t,z);
    }
    
    bool find(int target) {
        if(s.find(target)!=s.end())
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */