#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue{
    private:
        int front,rear;
        int arr[MAX_SIZE];
    public:
        Queue(): front(-1),rear(-1){}

        bool isEmpty(){
            return (front == -1);
        }
        bool isFull(){
            return (rear = MAX_SIZE - 1);
        }
    
    void enQueue(int value){
        if(isFull()){
            cout<<"can't do this operation"<<endl;
        }
        if(isEmpty()){
            front =0;
        }
        arr[++rear]=value;
        cout<<"enqueued"<<value<<"sucessfully"<<endl;
    }
    void deQueue(){
        if(isEmpty()) {
            cout << "queue is empty\n";
        }
        else{
            int value = arr[front++];
            cout<<"successfully dequeued"<<value<<endl;
            if(front>rear){
                front = rear = -1;
            }
        }
    }
    void displayFront(){
        if(isEmpty()){
            cout<<"Nothing to show\n";
        }
        else{
            cout<<"front of the  queue : "<<arr[front]<<endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"there is nothing to show"<<endl;
        }
        else{
            cout<<"Queueud elements are: \n";
            for(int i=front; i<=rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Queue myQueue;
    int choice, element;

    do {
        cout << "\nQueue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front Element\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> element;
                myQueue.enQueue(element);
                break;

            case 2:
                myQueue.deQueue();
                break;

            case 3:
                myQueue.displayFront();
                break;

            case 4:
                myQueue.display();
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}