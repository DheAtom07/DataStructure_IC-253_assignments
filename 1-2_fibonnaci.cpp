#include<iostream>
using namespace std;
void generateFibonacci(int n);

int main(){
    int a;
    cout<<"Enter input here : ";
    do{cin>>a;}while(a<=0);
    generateFibonacci(a);
}
void generateFibonacci(int n){
    int arr1[n+1];
    arr1[0]=0;
    arr1[1]=1;
    cout<<"0th element is : "<<arr1[0]<<endl;
    cout<<"1st element is : "<<arr1[1]<<endl;
    for(int i=2;i<=n;i++){
        arr1[i]=arr1[i-2]+arr1[i-1];
        cout<<i<<"th element is : "<<arr1[i]<<endl;
    }
}