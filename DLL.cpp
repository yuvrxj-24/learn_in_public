#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->prev = NULL;
    }
};
void print(Node* head)
{
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}
int getLength(Node* &head)
{
    int len=0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;

    }
    return len;
}
void inserathead(Node* &head,int d )
{
    Node* temp = new Node(d);
    temp ->next=head;
    head->prev =temp;
    head=temp; 
}
void insertattail(Node* &tail,int d )
{
    Node* temp = new Node(d);
    tail->next =temp;
    temp->prev=tail;
    tail=temp;
}
int main()
{
    Node* node1= new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    inserathead(head,6);
    print(head);

    insertattail(tail,7);
    print(head);
    cout<<"length is =>>"<<getLength(head)<<endl;
    return 0;
} 