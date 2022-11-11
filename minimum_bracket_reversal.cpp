#include <iostream>
using namespace std;
#include <stack>
int countBracketReversals(string input) {
	if(input.length()%2==1){
        return -1;
    }
    else{
        stack<char> s;
        for(int i=0;i<input.length();i++){
            /*agar { =>blindly push
            if(input[i]=='{'){
                s.push(input[i]);
            }
            /*agar } =>i)top={ then pop
            else if(input[i]=='}' and s.top()=='{'){
                s.pop();
            }
            /*ii)top=} then push
            else if(input[i]=='}' and s.top()=='}'){
                s.push(input[i]);
            }
            /*iii)stack empty tha pehle tab bhi push
            else if(input[i]=='}' and s.empty()==true){
                s.push(input[i]);
            }*/
            if(input[i]=='{'){
                s.push(input[i]);
            }
            else if(input[i]=='}'){
                if(s.empty()==true or s.top()=='}'){
                    s.push(input[i]);
                }
                else if(s.top()=='{'){
                    s.pop();
                }
            }
        }
        /*Now reached end ie. iteration over*/
        char top_character,second_topmost_character;
        int answer=0;
        while(s.empty()==false){
            /*Now took top 2 characters in these variables*/
            top_character=s.top();
            s.pop();
            second_topmost_character=s.top();
            s.pop();
            if(top_character==second_topmost_character){
                answer++;
            }
            else if(top_character!=second_topmost_character){
                answer=answer+2;//as then dono ko reverse karna padega
            }
        }
        return answer;
    }
}
int main(){
    string expression;
    cin>>expression;
    cout<<countBracketReversals(expression);
}