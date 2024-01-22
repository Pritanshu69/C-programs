#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node and data"<<value<<endl;
    }
};
void insertElement(Node* tail, int element, int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next=newNode;
    }
    else{
        Node* curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;  
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;  
    }
}

void display(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }
    while(tail != temp);
    cout<<endl;
}
int main(){
    Node* tail = NULL;
    
    insertElement(tail, 5, 3);
    display(tail);
    insertElement(tail, 3, 5);
    display(tail);

    return 0;
}