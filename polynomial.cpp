#include<iostream>
using namespace std;
class polynomial{
    private:
      struct node{
        int coeff;
        int exp;
        node* next;
        node(int data, int p){
            this->coeff=data;
            this->exp=p;
            next=nullptr;
        }
      }*head;
    public:
        node*getHead(){return head;}
        polynomial(){
            head=nullptr;
        }
}