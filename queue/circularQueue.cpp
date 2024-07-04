#include<iostream>
using namespace std;
const int MAX_SIZE = 5;

class CircularQueue{
    private:
    int front,rear;
    int arr[MAX_SIZE];
    
    public:
    CircularQueue() : front(-1), rear(-1) {}    

    bool isFull(){
        return(front == 0 && rear == MAX_SIZE-1)||(front=rear+1);
    }
    bool isEmpty(){
        return front == -1;
    }

    void insert(int item){
        if(isFull()){
            cout<<"can't  insert. Queue is full\n";
            return;
        }
        else{
            if(isEmpty()){
                front = 0;
            }
            rear=(rear+1)%MAX_SIZE;
            arr[rear]=item;
            cout<<item<<"inserted"<<endl;
        }
    }
    void remove(){
        if(isEmpty()){
            cout<<"no content"<<endl;
        }
        else {
            int item = arr[front];
            if(front==rear){
                front=rear=-1;
            }
            else{
                front=(front+1)%MAX_SIZE;
            }
            cout<<"delted"<<item<<endl;
        }
    }

    void displayQueue(){
        if(isEmpty()){
            cout << "No elements in the queue.\n";
        }
        else {
            cout<<"Circular Queue elements: ";

            int i= front;
            do{
                cout<<arr[i]<<" ";
                i=(i+1)%MAX_SIZE;
            }
            while(i!=(rear+1)%MAX_SIZE);
                cout<<endl;
            
        }
    }
};
int main() {
    CircularQueue myCircularQueue;
    int choice, element;

    do {
        cout << "\nCircular Queue Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> element;
                myCircularQueue.insert(element);
                break;

            case 2:
                myCircularQueue.remove();
                break;

            case 3:
                myCircularQueue.displayQueue();
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
