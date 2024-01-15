#include<iostream>
#include<stack>


using namespace std;

bool isOperand(char ch){
    return isalnum(ch); //NOTE - isalnum checks if the char is not zero!
}
//NOTE - function starts here

string postfixToinfix(const string& postfix){
    stack<string> operandStack;

    for(char ch: postfix){
        if(isOperand(ch)){
             operandStack.push(string(1,ch));
        }
       
       else{
        string operand2 = operandStack.top();
        operandStack.pop();
        string operand1 = operandStack.top();
        operandStack.pop();

        string newOperand = "(" + operand1 + ch + operand2 + ")";
        operandStack.push(newOperand);
       }
    }
    return operandStack.top();
} 
//NOTE - function ends here!

int main(){
    string postfixExpression;

    // Get postfix expression
    cout << "Enter a valid postfix expression: ";
    cin>>postfixExpression;

    string infixExpression = postfixToinfix(postfixExpression);
    
    cout<<"Postfix Expression: "<<postfixExpression<<endl;
    cout<<"Infix Expression: "<<infixExpression<<endl;

    return 0;
}
