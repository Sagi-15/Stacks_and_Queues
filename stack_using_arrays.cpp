#include <iostream>
using namespace std;
class Stack{
    private:
        int *data;
        int nextIndex;
        int capacity;
    public:
        Stack(int capacity){
            this->capacity=capacity;
            this->nextIndex=0;
            this->data=new int[this->capacity];
        }
        int size(){
            return this->nextIndex;
        }
        bool isEmpty(){
            return this->nextIndex==0;
        }
        void push(int element){
            if(this->nextIndex==capacity){
                cout<<"Stack is Full!"<<endl;
            }
            else{
                this->data[this->nextIndex]=element;
                this->nextIndex++;
            }
        }
        int pop(){
            if(isEmpty()==true){
                cout<<"Stack is Empty!"<<endl;
                return INT_MIN;
            }
            else{
                this->nextIndex--;
                return this->data[this->nextIndex];
            }
        }
        int top(){
            if(isEmpty()==true){
                cout<<"Stack is Empty!"<<endl;
                return INT_MIN;
            }
            else{
                return this->data[this->nextIndex-1];
            }
        }
};
int main(){
    Stack s(3);
    s.push(10);
    s.push(20);
    s.push(40);
    /*abhi tak 10,20,40 now wapas push =>overflow*/
    s.push(30);
    /*so stack full print hoga*/
    cout<<s.pop()<<endl;
    /*10,20 bacha*/
    cout<<s.pop()<<endl;
    /*10 bacha*/
    cout<<s.top()<<endl;
    /*so 10 print karega*/
    cout<<s.isEmpty()<<endl;
    /*as 10 there so false print*/
    cout<<s.pop()<<endl;
    /*Now empty ho ja*/
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
}