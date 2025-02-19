#include<iostream>
using namespace std;
int main(){
    int a,b,numerator,denominator,remainder;
    do{
    cout<<"Enter first integer : "<<endl;
    cin>>a;
    cout<<"Enter second integer : "<<endl;
    cin>>b;
    }while (a<=0 || b<=0);
    if (a>=b){
    numerator=a;
    denominator=b;
    }
    else if (a<b){
    numerator=b;
    denominator=a;
    }
    do{
        remainder=numerator%denominator;
        numerator=denominator;
        denominator=remainder;
    }while (remainder!=0);
    cout<<"The GCD of "<<a<<" and "<<b<<" is : "<<numerator;
}