#include<iostream>
#include<string>
using namespace std;

char* split(string myString);

int main(){

    string myString;
    getline(cin,myString);


}

char* split(string myString){

    char characterArray[myString.length()+1];
    for (int i=0;i<myString.length();i++){
            characterArray[i]=myString[i];
    }
    characterArray[myString.length()]="\0";
    int counter=0;
    char wordsArray[counter];
    for (char ch:characterArray){
        if (ch!=" "){
            counter++;
        }
        cout<<ch;
    }
    char array_of_words[counter];
    for (int i=0;i<counter;i++){
        
        char array_of_words[i]=
    }    
    return characterArray
}