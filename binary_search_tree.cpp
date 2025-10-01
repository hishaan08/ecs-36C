#include<iostream>
using namespace std;
struct Node{
    int val;
    Node*l,*r;
    Node(int v){
        val=v;
        l=r=NULL;
    }
};
Node*insert(Node*root,int v){
    if(!root)
        return new Node(v);
    if(v<root->val)
        root->l=insert(root->l,v);
    else
        root->r=insert(root->r,v);
    return root;
}
void inorder(Node*root){
    if(!root)
        return;
    inorder(root->l);
    cout<<root->val<<" ";
    inorder(root->r);
}
int main(){
    Node*root=NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,7);
    inorder(root);
}