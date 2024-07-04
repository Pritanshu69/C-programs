#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value): data(value),next(NULL){}
};
class Stack{
    private:
    Node* top;
    public:
    Stack():top(NULL){}
    bool isEmpty(){
        return top==NULL;
    }
    void push(int value){
        Node* newNode = new Node(value);
        newNode->next=top;
        top=newNode;
        cout<<value<<"pushed onto the stack"<<endl;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else{
            Node* temp=top;
            top=top->next;
            cout<<"popped: "<<temp->data<<endl;
            delete temp;
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"empty"<<endl;
        }
        else{
            cout<<"Top element of the stack is : "<<top->data<<endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"The stack is empty."<<endl;
        }
        else{
            cout<<"Stack elements: ";
            Node* curr = top;
            while(curr!=NULL){
                cout<<curr->data<<"  ";
                curr=curr->next;
            }
            cout<<endl;
        }
    }
        ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }

};
int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.display();

    myStack.peek();

    myStack.pop();

    myStack.display();

    return 0;
}
