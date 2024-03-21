//Find whether the given word is a vowel or consonent

#include<iostream>
using namespace std;

int main(){
    char x;
    char a[10] = {'a','e','i','o','u'};
    cout<<"Enter the character: ";
    cin>>x;
    for(int i = 0;i<5;i++){
        if(x == a[i]){
            cout<<"The character is a vowel";
            return 0;
        }
    }
    cout<<"The character is a consonent";
    

}