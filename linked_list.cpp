#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    for(Node*cur=head;cur;cur=cur->next)
        cout<<cur->data<<" ";
}