/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string expression) {
    stack<char> s;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='{' or expression[i]=='(' or expression[i]=='['){
            s.push(expression[i]);
        }
        else if(expression[i]=='}' or expression[i]==')' or expression[i]==']'){
            if((int)expression[i]-(int)s.top()==2 or (int)expression[i]-(int)s.top()==1){
                /*yaha tabhi ghuss when top mei { 
                    aur expression[i]=} or () or []
                    as unke ascii mei 2 or 1 ka difference*/
                s.pop();
            }
            else{
                /*top mei [ aur naya bracket introduced/closed 
                is ) then bracket not closed in proper order*/
                return false;
            }
        }
    }
    return s.empty();
    /*ie. now agar stack empty tabhi brackets opened are closed*/
}