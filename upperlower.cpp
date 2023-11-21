#include<iostream>

using namespace std;
int main() {
    char ch;
    cout << "Enter a character: ";
    cin>>ch;

    if(ch>=65 && ch<=90){
        cout<<"You have entered an uppercase character"<<endl;
    }
    else if (ch>=48 && ch<=57)
    {
        cout<<"You have entered a digit"<<endl;
    }
    else if (ch>=97 && ch<=122)
    {
         cout<<"You have entered a lowercase character"<<endl;
    }
    else{
        cout<<"You have entered a special character"<<endl;
    }
}