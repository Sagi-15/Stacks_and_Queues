/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;
#include <stack>
bool checkRedundantBrackets(string expression){
    /*boundary condition*/
    if(expression==""){
        return false;
    }
	stack<char> s;
    int count_of_characters_in_between_brackets=0;
    for(int i=0;i<expression.length();i++){
        if(expression[i]!=')'){
            s.push(expression[i]);
        }
        else if(expression[i]==')'){
            while(s.top()!='('){
                count_of_characters_in_between_brackets++;
                s.pop();
            }
            s.pop();
            if(count_of_characters_in_between_brackets==0 or count_of_characters_in_between_brackets==1){
                /*matlab uske andar kuch hai hi nahi or ek hi char hai
                eg-> a+(b)+c ka case*/
                return true;
            }
            else if(count_of_characters_in_between_brackets>1){
                /*matlab significant number of chars*/
                /*Can't return false here as not sure for other outer brackets only inner brackets checked*/
                count_of_characters_in_between_brackets=0;//for next pair(outer) ka redundancy check
            }
        }
    }
    /*No bracket =>also reach here so false return*/
    return false;
}
int main() {
    string input;
    cin >> input;
    cout<<(checkRedundantBrackets(input));
}