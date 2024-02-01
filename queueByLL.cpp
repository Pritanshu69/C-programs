#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value): data(value), next(NULL){}
};
class Queue{
    private:
    Node* front;
    Node* rear;
    public:
    Queue(): front(NULL), rear(NULL){}

    ~Queue(){
        while(front!=NULL){
            del();
        }
    }
    bool isEmpty(){
        return(front==NULL);
    }
    void insert(int value){
        Node* newNode = new Node(value);
        if(isEmpty()){
            front = rear = new Node(value);
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
    }
    void del(){
        if(!isEmpty()) {
            cout<<"Empty Queue"<<endl;
        }
        else{
            Node* temp=front;
            front=front->next;
            cout<<"deleted"<<temp->data<<endl;
            delete temp;
        }
    }
    void display(){
        if(isEmpty){
            cout<<"Empty Queue"<<endl;
        }
        else{
            Node* curr = front;
            while(curr!=NULL){
                cout<<curr->data<<" ";
                curr=curr->next;
            }
            cout<<endl;
        }
    }
};