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
Node*rotR(Node*x){
    Node*y=x->l;
    x->l=y->r;
    y->r=x;
    return y;
}
Node*rotL(Node*x){
    Node*y=x->r;
    x->r=y->l;
    y->l=x;
    return y;
}
Node*splay(Node*root,int v){
    if(!root||root->val==v)
        return root;
    if(v<root->val){
        if(!root->l)
            return root;
        if(v<root->l->val){
            root->l->l=splay(root->l->l,v);
            root=rotR(root);
        }
        else if(v>root->l->val){
            root->l->r=splay(root->l->r,v);
            if(root->l->r)
                root->l=rotL(root->l);
        }
        return root->l?rotR(root):root;
    }
    else{
        if(!root->r)
            return root;
        if(v>root->r->val){
            root->r->r=splay(root->r->r,v);
            root=rotL(root);
        }
        else if(v<root->r->val){
            root->r->l=splay(root->r->l,v);
            if(root->r->l)
                root->r=rotR(root->r);
        }
        return root->r?rotL(root):root;
    }
}
Node*insert(Node*root,int v){
    if(!root)
        return new Node(v);
    root=splay(root,v);
    if(root->val==v)
        return root;
    Node*n=new Node(v);
    if(v<root->val){
        n->r=root;
        n->l=root->l;
        root->l=NULL;
    }
    else{
        n->l=root;
        n->r=root->r;
        root->r=NULL;
    }
    return n;
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
    root=insert(root,10);
    root=insert(root,20);
    root=splay(root,10);
    inorder(root);
}