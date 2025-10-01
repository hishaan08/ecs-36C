#include<iostream>
using namespace std;
#define MAX 100
class Queue{
    int arr[MAX],front,rear;
public:
    Queue(){front=rear=0;}
    void enqueue(int x){
        if(rear<MAX)
            arr[rear++]=x;
    }
    void dequeue(){
        if(front<rear)
            front++;
    }
    int peek(){return(front<rear)?arr[front]:-1;}
    bool empty(){return front==rear;}
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    cout<<q.peek();
}