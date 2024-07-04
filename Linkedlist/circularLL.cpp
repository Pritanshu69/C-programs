#include <iostream>
#include <map>
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
        cout<<"memory is free for node and data "<<value<<endl;
    }
};
void insertNode(Node*& tail, int element, int d) {
    //empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    } 
    else {
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while (curr->data != element) {
            curr = curr->next;
        }

        //element found -> curr is representing element node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL ){
        cout<<"The LL is empty"<<endl;
        return;
    }
    else{
        //it's not empty

        Node* prev = tail;
        Node* curr = tail->next;
        while (curr->data != value){
            prev = curr;
            curr = curr->next;
        }
            prev->next = curr->next;
            curr->next=NULL;
            delete curr;
    }
}


void display(Node* tail){
    Node* temp = tail;
        if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }
    while(tail != temp);
    cout<<endl;
}
int main(){
    Node* tail = NULL;
    
    insertNode(tail, 5, 3);
    display(tail);
    insertNode(tail, 3, 5);
    display(tail);
    deleteNode(tail, 5);
    display(tail);

    return 0;
}