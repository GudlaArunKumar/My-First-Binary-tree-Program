#include <iostream>
#ifndef Queue_h
#define Queue_h
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Queue
{
public:
    int size;
    int front;
    int rear;
    Node **Q;
Queue()
{
    front=rear=0;
    size =10;
    Q=new Node *[size];
}
Queue(int size)
{
    front=rear=0;
    this->size=size;
    Q=new Node *[this->size];
}

void enqueue(Node *x)
{
if((rear+1)%size==front)
cout << "Queue is Full" << endl;
else
{
rear=(rear+1)%size;
Q[rear]=x;
}
}
Node * dequeue()
{
Node *x=NULL;
if(front==rear)
cout << "Queue is Empty "<< endl;
else
{
front=(front+1)%size;
x=Q[front];
}
return x;
}
int isEmpty()
{
return front==rear;
}
};

#endif