#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertathead(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp ->next = head;
    head->prev = temp;
    head=temp;
}
void insetatatail(Node* &tail,int d)
{
    Node* temp = new Node(d);
    tail ->next = temp;
    temp ->prev = tail;
    tail = temp;
}
void insertatanyposition(Node* &head,Node* &tail,int position,int d)
{
    if(position==1){
        insertathead(head,d);
        return;
    }
    Node *temp =head;
    int cnt =1;
    while(cnt<position-1)
    {
        temp =temp->next;
        cnt++;
    }
    if(temp->next ==NULL)
    {
        insetatatail(tail,d);
        return;
    }

    Node* newnode = new Node(d);
    newnode ->next = temp->next;
    temp ->next ->prev = newnode;
    newnode->prev = temp;
    temp ->next = newnode;





}
int main()
{
    Node* node1=new Node(20);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    return 0;
}