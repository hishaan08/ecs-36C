#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    int arr[MAX],top;
public:
    Stack(){top=-1;}
    void push(int x){
        if(top<MAX-1)
            arr[++top]=x;
    }
    void pop(){
        if(top>=0)
            top--;
    }
    int peek(){return(top>=0)?arr[top]:-1;}
    bool empty(){return top==-1;}
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    cout<<s.peek();
}