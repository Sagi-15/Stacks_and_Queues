/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
#include <iostream>
using namespace std;
int* stockSpan(int *price,int size){
    int *solution=new int[size];
    for(int i=size-1;i>=0;i--){
        int count=1;
        for(int j=i-1;j>=0;j--){
            if(price[j]<price[i]){
                count++;
            }
        }
        solution[i]=count;
    }
    return solution;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int *arr=stockSpan(A,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}