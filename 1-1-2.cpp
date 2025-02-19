#include <iostream>
using namespace std;

int GCDof(int a, int b);

int main(){
    int a,b;
    do{
    cout<<"enter a : ";
    cin>>a;
    cout<<"enter b : ";
    cin>>b;
    } while(a <=0 || b <=0);
    cout<<GCDof(a,b);
}

int GCDof(int a,int b){

    int numerator,denominator,remainder;
    if (a>=b){
        numerator=a;
        denominator=b;
    }
    else if (a<b){
        numerator=b;
        denominator=a;
    }
    while (remainder!=0)    // officilaly it should be denominator !=0 butt........
    {
        remainder=numerator%denominator;
        numerator=denominator;
        denominator=remainder;
    };
    return numerator;
}