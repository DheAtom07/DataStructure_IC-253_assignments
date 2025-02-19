#include<iostream>
#include<string>
using namespace std;

int main(){
    string input_string;
    cout<<"Enter : ";
    getline(cin,input_string);
    int counter=0;
    for(char chr:input_string){
        counter++;
    }
    for (int i=counter;i>=0;i--){
        cout<<input_string[i];
    }
    cout<<endl;
    cout<<"The length of the string is : "<<counter<<endl;
    for(int i=0;i<(input_string.length()/2);i++){
        if(input_string[i]!=input_string[input_string.length()-i-1]){
            cout<<"String is not pelindrome.";
            break;
        }
        if(i==input_string.length()/2-1){
            cout<<"The string is pelindrome.";
            break;
        }
    }
}