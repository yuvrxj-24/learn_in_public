#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    ~Node()
    {
        int value =this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }
};

void insertathead(Node* &head,int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertattail(Node* &tail,int d)
{
    Node* temp  = new Node(d);
    tail->next = temp;
    tail = temp;
}

void inseratposition(int position , Node*tail,Node* &head,int d)
{
    if(position ==1){
        insertathead(head,d);
        return;
    }
    
    Node* temp = head;
    int cnt =1;
    while(cnt<position -1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next ==NULL){
        insertattail(tail,d);
        return;
    }
    
    Node* newnode = new Node(d);
    newnode ->next = temp->next;
    temp ->next=newnode;
}


void print(Node* &head)
{
    Node* temp =head;
    while(temp!=NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void deletenode(int position,Node* &head)
{
   //deleting at first node
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev =NULL;

        int cnt =1;
        while(cnt<position)
        {
            prev=curr;
            curr = curr->next;
            cnt++;
        }
        prev ->next = curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    Node* node1 = new Node(24);

    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertathead(head,9);
    print(head);

    insertattail(tail,6);
    print(head);
    print(tail);
    print(head);
    inseratposition(4,tail,head,7);
    print(head);
    deletenode(2,head);
    print(head);
    deletenode(1,head);
    print(head);
    deletenode(2,head);
    print(head);
    print(tail);
    deletenode(1,tail);
    print(tail);
}