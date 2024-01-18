#include <iostream>
using namespace std;

const int MAX_SIZE = 100; //max size of the array

class Stack{
private:
    int top; //top of the stack
    int arr[MAX_SIZE]; //NOTE - array to store stack elements
public:
    Stack(){
    top=-1;
    }
    bool isEmpty(){
        return (top == -1); //NOTE - function to check if stack is empty or not
    }
    //NOTE - function to push an element 
    void push(int value){
        if(top == MAX_SIZE -1 ){
            cout<<"Stack overflow can't push"<< value <<endl;
            return;
        }
        arr[++top] = value;
        cout<<"Pushed element"<< value << "onto the stack" << endl;
    }
    //NOTE - fucntion to pop an element
    void pop(){
        if(isEmpty()){
            cout<<"Stack underflow can't pop"<<endl;
            return;
        }
        cout<<"popped element"<< arr[top--]<<"from the stack"<<endl;
    }
    //NOTE - fucntion for peek
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty can't peek"<<endl;
            return;
        }
        cout<<"Top of the stack"<< arr[top]<<endl;
    }
       //NOTE -  Function to display all elements of the stack
    void display() {
        if (isEmpty()) {
            std::cout << "The stack is empty. Nothing to display.\n";
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main(){
    Stack stack;

    int choice,value;

    do{
        cout<< "1.push"<<endl;
        cout<< "2.pop"<<endl;
        cout<< "3.peek"<<endl;
        cout<< "4.display"<<endl;
        cout<< "5.exit"<<endl;

        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the value to push onto the stack"<<endl;
                cin>>value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"invalid choice"<<endl;
                break;
        }
    }
    while(choice!=5);
    return 0;
}
