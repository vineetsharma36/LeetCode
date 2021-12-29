/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* temp=q.front().first;
            int level=q.front().second;
            q.pop();
            if(temp->left)
                q.push({temp->left,level+1});
            if(temp->right)
                q.push({temp->right,level+1});
            if(q.empty()){
                temp->next=NULL;
            }
            else{
                Node* temp1=q.front().first;
                int level1=q.front().second;
                if(level==level1){
                    temp->next=temp1;
                }
                else{
                    temp->next=NULL;
                }
            }            
        }
        return root;
    }
};