#include <iostream>
#ifndef Stack_h
#define Stack_h

class Stack{
public:
    int siz;
    int top;
    Node **S;
Stack()
{ siz=20;
top=-1;
S=new Node* [siz];
}
Stack(int siz)
{
    this->siz=siz;
    top=-1;
    S=new Node* [this->siz];
}

void push(Node *x)
{
    if(top==siz-1)
    {
        cout <<"Stack Overflow" << endl;
    }
    else{
        top++;
        S[top] = x;
    }
}

Node * pop()
{
    Node *x=NULL;
    if(top==-1)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        x=S[top];
        top--;
    }
return x;
}

int isEmptyStack()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
};

#endif