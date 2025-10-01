#include<iostream>
using namespace std;
enum Color{RED,BLACK};
struct Node{
    int data;
    Color color;
    Node*left,*right,*parent;
    Node(int val):data(val),color(RED),left(NULL),right(NULL),parent(NULL){}
};
class RedBlackTree{
    Node*root;
    void rotateLeft(Node*x){
        Node*y=x->right;
        x->right=y->left;
        if(y->left) y->left->parent=x;
        y->parent=x->parent;
        if(!x->parent) root=y;
        else if(x==x->parent->left) x->parent->left=y;
        else x->parent->right=y;
        y->left=x;
        x->parent=y;
    }
    void rotateRight(Node*y){
        Node*x=y->left;
        y->left=x->right;
        if(x->right) x->right->parent=y;
        x->parent=y->parent;
        if(!y->parent) root=x;
        else if(y==y->parent->left) y->parent->left=x;
        else y->parent->right=x;
        x->right=y;
        y->parent=x;
    }
    void fixInsert(Node*z){
        while(z->parent&&z->parent->color==RED){
            if(z->parent==z->parent->parent->left){
                Node*y=z->parent->parent->right;
                if(y&&y->color==RED){
                    z->parent->color=BLACK;
                    y->color=BLACK;
                    z->parent->parent->color=RED;
                    z=z->parent->parent;
                }
                else{
                    if(z==z->parent->right){
                        z=z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color=BLACK;
                    z->parent->parent->color=RED;
                    rotateRight(z->parent->parent);
                }
            }
            else{
                Node*y=z->parent->parent->left;
                if(y&&y->color==RED){
                    z->parent->color=BLACK;
                    y->color=BLACK;
                    z->parent->parent->color=RED;
                    z=z->parent->parent;
                }
                else{
                    if(z==z->parent->left){
                        z=z->parent;
                        rotateRight(z);
                    }
                    z->parent->color=BLACK;
                    z->parent->parent->color=RED;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->color=BLACK;
    }
    Node*bstInsert(Node*root,Node*z){
        if(!root) return z;
        if(z->data<root->data){
            root->left=bstInsert(root->left,z);
            root->left->parent=root;
        }
        else{
            root->right=bstInsert(root->right,z);
            root->right->parent=root;
        }
        return root;
    }
    void fixDelete(Node*x){
        while(x!=root&&(!x||x->color==BLACK)){
            if(x==x->parent->left){
                Node*w=x->parent->right;
                if(w&&w->color==RED){
                    w->color=BLACK;
                    x->parent->color=RED;
                    rotateLeft(x->parent);
                    w=x->parent->right;
                }
                if((!w->left||w->left->color==BLACK)&&(!w->right||w->right->color==BLACK)){
                    w->color=RED;
                    x=x->parent;
                }
                else{
                    if(!w->right||w->right->color==BLACK){
                        if(w->left) w->left->color=BLACK;
                        w->color=RED;
                        rotateRight(w);
                        w=x->parent->right;
                    }
                    w->color=x->parent->color;
                    x->parent->color=BLACK;
                    if(w->right) w->right->color=BLACK;
                    rotateLeft(x->parent);
                    x=root;
                }
            }
            else{
                Node*w=x->parent->left;
                if(w&&w->color==RED){
                    w->color=BLACK;
                    x->parent->color=RED;
                    rotateRight(x->parent);
                    w=x->parent->left;
                }
                if((!w->right||w->right->color==BLACK)&&(!w->left||w->left->color==BLACK)){
                    w->color=RED;
                    x=x->parent;
                }
                else{
                    if(!w->left||w->left->color==BLACK){
                        if(w->right) w->right->color=BLACK;
                        w->color=RED;
                        rotateLeft(w);
                        w=x->parent->left;
                    }
                    w->color=x->parent->color;
                    x->parent->color=BLACK;
                    if(w->left) w->left->color=BLACK;
                    rotateRight(x->parent);
                    x=root;
                }
            }
        }
        if(x) x->color=BLACK;
    }
    Node*successor(Node*x){
        Node*cur=x->right;
        while(cur&&cur->left) cur=cur->left;
        return cur;
    }
public:
    RedBlackTree():root(NULL){}
    void insert(int data){
        Node*z=new Node(data);
        root=bstInsert(root,z);
        fixInsert(z);
    }
    void remove(int data){
        Node*z=root;
        while(z&&z->data!=data){
            if(data<z->data) z=z->left;
            else z=z->right;
        }
        if(!z) return;
        Node*y=z;
        Color yOriginalColor=y->color;
        Node*x;
        if(!z->left){
            x=z->right;
            if(x) x->parent=z->parent;
            if(!z->parent) root=x;
            else if(z==z->parent->left) z->parent->left=x;
            else z->parent->right=x;
        }
        else if(!z->right){
            x=z->left;
            if(x) x->parent=z->parent;
            if(!z->parent) root=x;
            else if(z==z->parent->left) z->parent->left=x;
            else z->parent->right=x;
        }
        else{
            y=successor(z);
            yOriginalColor=y->color;
            x=y->right;
            if(y->parent==z){
                if(x) x->parent=y;
            }
            else{
                if(y->parent){
                    if(y==y->parent->left) y->parent->left=x;
                    else y->parent->right=x;
                }
                if(x) x->parent=y->parent;
                y->right=z->right;
                if(y->right) y->right->parent=y;
            }
            if(!z->parent) root=y;
            else if(z==z->parent->left) z->parent->left=y;
            else z->parent->right=y;
            y->parent=z->parent;
            y->left=z->left;
            if(y->left) y->left->parent=y;
            y->color=z->color;
        }
        delete z;
        if(yOriginalColor==BLACK&&x) fixDelete(x);
    }
    void inorder(Node*r){
        if(!r) return;
        inorder(r->left);
        cout<<r->data<<"("<<(r->color==RED?"R":"B")<<") ";
        inorder(r->right);
    }
    void print(){
        inorder(root);
        cout<<"\n";
    }
};
int main(){
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    cout<<"Tree: "; rbt.print();
    rbt.remove(20);
    cout<<"After deleting 20: "; rbt.print();
}
