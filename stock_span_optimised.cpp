/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <stack>
using namespace std;
template <typename T,typename V>
class Pair{
    public:
        T data;
        V days;
        Pair(T data,V days){
            this->data=data;
            this->days=days;
        }
};
int *stockSpan(int *price, int size){
    int *solution_array=new int[size];
    stack<Pair<int,int>> s;
    for(int i=0;i<size;i++){
        int days=1;
        if(s.empty()==true or s.top().data>price[i]){
            Pair<int,int> p(price[i],1);
            /*1 push as aagla hi bada so aage not check*/
            solution_array[i]=1;
            s.push(p);
        }
        else if(s.top().data<=price[i]){
            while(s.empty()==false and s.top().data<price[i]){
                days+=s.top().days;
                s.pop();
            }
            Pair<int,int> p(price[i],days);
            s.push(p);
            solution_array[i]=days;
        }
    }
    return solution_array;
}
int main(){
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int *solution=stockSpan(price,n);
    for(int i=0;i<n;i++){
        cout<<solution[i]<<" ";
    }
    delete []solution;
}