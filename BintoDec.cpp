#include<iostream>
#include<math.h>

using namespace std;

int main(){

    int n;
    cout<<"Enter a binary number"<<endl;
    cin>>n;

    int i = 0;
    int ans = 0;

    while(n!=0){

        int digit = n & 1;

        if(digit == 1){
            ans = ans + pow(2,i);
        }
        n=n/10;
        i++;
    }
    cout<<"Decimal value: "<<ans<<endl;
}