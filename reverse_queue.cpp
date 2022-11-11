/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;
#include <queue>
void reverseQueue(queue<int> &input) {
    /*Base case: Agar queue mei 0 or 1 element no need to reverse*/
    if(input.size()==0 or input.size()==1){
        return;
    }
    /*Storing initial front and popping from queue*/
	int initial_front=input.front();
    input.pop();
    /*Using recursion to reverse the rest part of list*/
    reverseQueue(input);
    /*Assume ki recursion nei aapna kaam done ie. reversed*/
    /*now insert at last previous front*/
    input.push(initial_front);
}