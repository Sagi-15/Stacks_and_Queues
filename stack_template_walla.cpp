#include <iostream>
using namespace std;
template <typename T>
class Stack{
    private:
        T *data;
        int nextIndex;
        int capacity;
    public:
        Stack(){
            this->capacity=5;
            this->nextIndex=0;
            this->data=new T[this->capacity];
        }
        int size(){
            return this->nextIndex;
        }
        bool isEmpty(){
            return this->nextIndex==0;
        }
        void push(T element){
            if(this->nextIndex==capacity){
                T *newData=new T[2*capacity];
                for(int i=0;i<capacity;i++){
                    newData[i]=this->data[i];
                }
                T *p=this->data;
                this->data=newData;
                delete []p;
            }
            this->data[this->nextIndex]=element;
            this->nextIndex++;
        }
        T pop(){
            if(isEmpty()==true){
                cout<<"Stack is Empty!"<<endl;
                return 0;
            }
            else{
                this->nextIndex--;
                return this->data[this->nextIndex];
            }
        }
        T top(){
            if(isEmpty()==true){
                cout<<"Stack is Empty!"<<endl;
                return 0;
            }
            else{
                return this->data[this->nextIndex-1];
            }
        }
};
int main(){
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    s.push('f');
    s.push('g');
    s.push('h');
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