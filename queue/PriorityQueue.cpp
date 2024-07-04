#include<iostream>
#include<queue>

using namespace std;

class PriorityQueue{
    private:
    priority_queue<int>pq;
    public:
    bool isEmpty(){
        return pq.empty();  
    }
    void insert(int value){
        pq.push(value);
        cout<<"Inserted"<<value<<endl;
    }
    void del(){
        if(isEmpty()){
            cout<<"Empty Queue"<<endl;
        }
        else{
            int deletedValue=pq.top();
            pq.pop();
            cout<<"Deleted"<<deletedValue<<endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Empty Queue"<<endl;
        }
        else{
            priority_queue<int>tempPq=pq;
            while(!tempPq.empty()){
                cout<<tempPq.top()<<" ";
                tempPq.pop();
            }
            cout<<endl;
        }
    }
};
int main() {
    PriorityQueue priorityQueue;
    int choice, value;

    do {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. isEmpty()\n";
        cout << "2. insert()\n";
        cout << "3. del()\n";
        cout << "4. display()\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (priorityQueue.isEmpty()) {
                    cout << "Priority queue is empty.\n";
                } else {
                    cout << "Priority queue is not empty.\n";
                }
                break;

            case 2:
                cout << "Enter the value to insert: ";
                cin >> value;
                priorityQueue.insert(value);
                break;

            case 3:
                priorityQueue.del();
                break;

            case 4:
                priorityQueue.display();
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
