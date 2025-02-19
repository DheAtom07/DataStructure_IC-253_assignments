#include<iostream>
using namespace std;
float calculateArea(float l, float w);
float calculatePerimeter(float l, float w);
int main(){
    float leng1h, w1dth;
    do{
    cout<<"Enter the value of length : ";
    cin>>leng1h;
    cout<<"Enter the value of width : ";
    cin>>w1dth;}while(leng1h<=0 || w1dth<=0);
    cout<<"The area of ractangle is : "<<calculateArea(leng1h,w1dth)<<endl;
    cout<<"The perimeter of ractangle is : "<<calculatePerimeter(leng1h,w1dth);
}

float calculateArea(float l, float w){
    return l*w;
}

float calculatePerimeter(float l, float w){
    return 2*(l+w);
}