#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int val;
   Node* left;
   Node* right;
   Node(int val){
    this->val=val;
    this->left=NULL;
    this->right=NULL;
   }
};
Node* takeInputOfTree(){
    int n;
    cin>>n;
    Node* root;
    if(n==-1) root=NULL;
    else root=new Node(n);

    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty()){
        //1. ber kore ana
        Node* p=q.front();
        q.pop();

       //2. jabotio kaj
        int l,r;
        cin>>l>>r;
        Node* left;
        Node* right;

        if(l==-1)  left=NULL;
        else left=new Node(l);
        if(r==-1)  right=NULL;
        else right=new Node(r);

        p->left=left;
        p->right=right;
        if(p->left) q.push(p->left);
        if(p->right)  q.push(p->right);

    }
    return root;
}

int countLeafNodes(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    else{
        int l=countLeafNodes(root->left);
        int r=countLeafNodes(root->right);
        return l+r;
    }
}
int main(){
    Node* root=takeInputOfTree();
    int leafNodes=countLeafNodes(root);
    cout<<leafNodes<<" ";
    return 0;
}