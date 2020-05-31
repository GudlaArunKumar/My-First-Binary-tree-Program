#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
using namespace std;


class Tree{
public:
Node *root;

Tree(){root=NULL;}
void Treecreate();
void preOrder(Node *p);
void InOrder(Node *p);
void IpreOrder(Node *p);
void IinOrder(Node *t);
};

void Tree::Treecreate()
{
    Node *p,*tmp;
    int x;
    Queue q(20);
    root=new Node;
    cout <<"Enter the data for root" << endl;
    cin >> x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    
    while(!q.isEmpty())
    {
        p=q.dequeue();
        cout <<"Enter the data of left child of " <<p->data << ":";
        cin >> x;
        if(x!=-1)
        {
            tmp=new Node;
            tmp->data=x;
            tmp->lchild=tmp->rchild=NULL;
            p->lchild=tmp;
            q.enqueue(tmp);
        }
        cout <<"Enter the data of right child of " <<p->data << ":";
        cin >> x;
        if(x!=-1)
        {
            tmp=new Node;
            tmp->data=x;
            tmp->lchild=tmp->rchild=NULL;
            p->rchild=tmp;
            q.enqueue(tmp);
        }
    }
}

void Tree::preOrder(Node *p)
{
    if(p)
    {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }

}

void Tree::InOrder(Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }

}

void Tree::IpreOrder(Node *t)
{
    Stack stk(30);
    while(t!=NULL || !stk.isEmptyStack())
    {
      if(t!=NULL)
      {
          cout << t->data << " ";
          stk.push(t);
          t=t->lchild;
      }
      else
      {
          t=stk.pop();
          t=t->rchild;
      }
   }
cout << endl;
}

void Tree::IinOrder(Node *t)
{
    Stack st(30);
    while(t!=NULL || !st.isEmptyStack())
    {
      if(t!=NULL)
      {
          st.push(t);
          t=t->lchild;
      }
      else
      {
          t=st.pop();
          cout << t->data << " ";
          t=t->rchild;
      }
   }
cout << endl;
}

int countAllNodes(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=countAllNodes(p->lchild);
        y=countAllNodes(p->rchild);
        return x+y+1;
    }
    else
    return 0;
}

int countingLeafNode(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=countingLeafNode(p->lchild);
        y=countingLeafNode(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
    {
        return x+y+1;
    }
    else
    {
        return x+y;
    }
    }
    return 0;
    
}

int main()
{
    Tree T;
    T.Treecreate();
    cout <<"Elements in the tree are by PreOrder wise: " << endl;
    T.IpreOrder(T.root);
    cout << endl;
    cout << "InOrder Traversal elements: " << endl;
    T.InOrder(T.root);
    cout << "Counting All the Node of Tree: " << countAllNodes(T.root) << endl;
    cout << "Counting Leaf Node of Tree: " << countingLeafNode(T.root) << endl;
    return 0;
}
