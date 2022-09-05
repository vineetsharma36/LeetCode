/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            while(n--){
                Node* temp=q.front();
                for(auto& x: temp->children){
                    q.push(x);
                }
                v.push_back(temp->val);
                q.pop();
            }
            res.push_back(v);
        }
        return res;
    }
};