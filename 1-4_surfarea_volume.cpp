#include<iostream>
using namespace std;
float calculateVolume(float r,float h);
float calculateSurfaceArea(float r, float h);
int main(){
    float radius,height;
    do{
        cout<<"Enter radius here : "<<endl;
        cin>>radius;
        cout<<"Enter height here : "<<endl;
        cin>>height;
    }while(radius<=0 || height<=0);
    cout<<"The volume of cylinder is : "<<calculateVolume(radius,height)<<endl;
    cout<<"The surface area of cylinder is : "<<calculateSurfaceArea(radius,height);
}
float calculateVolume(float r, float h){
    return 3.14*r*r*h;
}
float calculateSurfaceArea(float r, float h){
    return 6.28*r*h;
}