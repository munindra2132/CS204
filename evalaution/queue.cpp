#include<bits/stdc++.h>

using namespace std;

struct node
{
    int x;
    node *nxt;
}*front=NULL,*rear=NULL;

void enqueue(int val)
{  node *temp=new node;

 if (rear == NULL) {
      rear = new node;
      rear->nxt = NULL;
      rear->x = val;
      front = rear;
   } else {
      temp=new node;
      rear->nxt = temp;
      temp->x = val;
      temp->nxt = NULL;
      rear = temp;
   }
    
}

void dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue empty";
        return;
    }
    node *temp;
    temp=front;
    front=front->nxt;
    cout<<temp->x<<" value is deleted"<<endl;
    delete temp;
    return;
}

void isEmpty()
{
    if(front==NULL)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return;
}

void peek()
{
    cout<<front->x<<" is the front value"<<endl;
}
int main()
{
    enqueue(7);
    enqueue(4);
    dequeue();
    enqueue(2);
    dequeue();
    enqueue(10);
    node*temp=front;
   /* while(temp!=NULL)
    {
    	cout<<temp->x<<" ";
    	temp=temp->nxt;
    }*/
    cout<<endl;
    dequeue();
    peek();
    dequeue();
    isEmpty();
    dequeue();
    dequeue();
    isEmpty();
    return 0;
}
