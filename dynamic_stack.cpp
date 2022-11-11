#include <iostream>
using namespace std;
class Stack{
    private:
        int *data;
        int nextIndex;
        int capacity;
    public:
        Stack(){
            this->capacity=5;
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
                int *newData=new int[2*capacity];
                for(int i=0;i<capacity;i++){
                    newData[i]=this->data[i];
                }
                int *p=this->data;
                this->data=newData;
                delete []p;
            }
            this->data[this->nextIndex]=element;
            this->nextIndex++;
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
    Stack s;
    s.push(10);
    s.push(20);
    s.push(40);
    s.push(30);
    s.push(50);
    s.push(60);
    s.push(70);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
}