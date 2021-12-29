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
    bool helper(TreeNode* p, TreeNode* q){
        if(p->val!=q->val)
            return false;
        if((p->left && q->left==NULL) || (p->left==NULL && q->left)){
            return false;
        }
        if((p->right && q->right==NULL) || (p->right==NULL && q->right)){
            return false;
        }
        if(p->left && p->right){
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
        else if(p->left){
            return isSameTree(p->left,q->left);
        }
        else if(p->right){
            return isSameTree(p->right,q->right);
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL && q!=NULL || p!=NULL && q==NULL){
            return false;
        }
        return helper(p,q);
    }
};