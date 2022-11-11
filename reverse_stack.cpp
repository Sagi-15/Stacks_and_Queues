/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
using namespace std;
#include <stack>
void reverseStack(stack<int> &input, stack<int> &extra){
    /*Base case*/
    if(input.empty()==true or input.size()==1){
        /*matlab kuch hai hi nahi so reverse karna nahi
        also 1 element =>reverse bhi same
        so kuch karne ki jarurat nahi*/
        return;
    }
    /*pehle save the initial top element so that use baad mei*/
    int initial_top=input.top();
    /*Now pop the input stack*/
    input.pop();
    /*call recursion to reverse the new stack*/
    reverseStack(input,extra);
    /*Now assume that woh part reversed hai
    put the elements from input to extra/helper*/
    while(!input.empty()){
        int newElement=input.top();
        input.pop();
        extra.push(newElement);
    }
    /*Now put the initial top at input stack*/
    input.push(initial_top);
    /*Now all elements from helper back to input*/
    while(!extra.empty()){
        int newElement=extra.top();
        extra.pop();
        input.push(newElement);
    }
}