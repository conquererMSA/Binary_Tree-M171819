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
void levelOrder(Node* root){
     queue<Node*> q;
     q.push(root);
     while(!q.empty()){
        // 1. ber kore ana.
        Node* f=q.front();
        q.pop();

        //2. jabotio kaj kora
        cout<<f->val<<" ";

        //3. children queue te rakha
        // if(f->right) q.push(f->right);10 30 20 50 90 40 80 70 100 60
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
     }
}
int main(){
    Node* root=takeInputOfTree();
   levelOrder(root);
    return 0;
}