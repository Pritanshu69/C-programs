#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    int a=0;
    int b=1;

    for(int i=0; i<=n; i++){
        int c = a+b;
        cout<<c<<endl;

        a=b;
        b=c;
    }
}