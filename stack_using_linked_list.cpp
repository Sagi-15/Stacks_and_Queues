#include <iostream>
using namespace std;
template <typename T>
class Node{
    public:
        T data;
        Node<T> *next;
        Node(T data){
            this->data=data;
            this->next=NULL;
        }
};
template <class T>
class Stack{
    private:
        Node<T> *head;
        int total_size;
    public:
        Stack(){
            this->head=NULL;
            this->total_size=0;
        }
        bool isEmpty(){
            return this->total_size==0;
        }
        int size(){
            return this->total_size;
        }
        void push(T data){
            Node<T> *newNode=new Node<T>(data);
            newNode->next=this->head;
            this->head=newNode;
            this->total_size++;
        }
        T pop(){
            if(this->total_size==0){
                return 0;
            }
            else{
                Node<T> *temp=this->head;
                T x=temp->data;
                this->head=(this->head)->next;
                delete temp;
                this->total_size--;
                return x;
            }
        }
        T top(){
            if(this->total_size==0){
                return 0;
            }
            else{
                return (this->head)->data;
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