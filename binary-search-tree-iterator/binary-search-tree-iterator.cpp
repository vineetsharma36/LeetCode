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
class BSTIterator {
public:
    void helper(TreeNode* root, vector<int> &v){
        if(root->left)
            helper(root->left,v);
        v.push_back(root->val);
        if(root->right)
            helper(root->right,v);
    }
    vector<int> v;
    int pos=0;
    BSTIterator(TreeNode* root) {
        if(root!=NULL)
            helper(root,v);
    }
    
    int next() {
        pos++;
        return v[pos-1];
    }
    
    bool hasNext() {
        if(pos==v.size())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */