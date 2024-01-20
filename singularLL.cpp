#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    //destructor
    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node* &head , int d){
    
    //NOTE - new node

    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    //NOTE - new node and current node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, int position, int d){
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp->next;
        count++;
    }
    Node* nodeToInsert = new Node(d);

    nodeToInsert-> next = temp-> next;

    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr-> next;
            count++;
        }
        prev->next = curr-> next;
        curr->next = NULL;
        delete curr;
    }
}

void display(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);    //created new node

    Node* head = node1;             //head pointed to new node
    Node* tail = node1;             //head pointed to new node

    display(head);

    insertAtTail(tail , 12);      
    display(head);

    insertAtTail(tail , 15);      
    display(head);

    insertAtTail(tail , 22);      
    display(head);

    insertAtPosition(head, 3, 26);
    display(head);
   
    insertAtPosition(head, 1, 36);
    display(head);

    deleteNode(2, head);
    display(head);
    return 0;
}