#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

//traversing a DLL

int getLength(Node* head){
        int len = 0;
        Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

//insert at head

void inserAthead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head->prev=temp;
    head=temp;
}

//display of DLL

void display(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data<< " ";
        temp = temp -> next;
    }
    cout<<endl;
}

void inserAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail=temp;
}

void insertAtPosition(Node* &head,Node* &tail, int position, int d){
    if(position==1){
        inserAthead(head, d);
        return;
    }
    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        inserAtTail(tail,d);
        return;
    }
    Node* nodeToInsert = new Node(d);

    nodeToInsert-> next = temp-> next;

    temp->next = nodeToInsert;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    display(head);

    cout<<getLength(head)<<endl;

    inserAthead(head, 13);
    display(head);
   
    inserAthead(head, 8);
    display(head);
   
    inserAtTail(tail, 69);
    display(head);

    return 0;
}