#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longest_substring(string s){
    unordered_map<char, int> charIndex;
    int start = 0; 
    int maxLength = 0;

    for(int end = 0; end<s.length(); end++){
        if(charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }

        charIndex[s[end]] = end;

        maxLength = max(maxLength, end - start + 1);
    }
    cout<<"The maxLength is "<<maxLength;

    return maxLength;

}

int main(){
    string s;

    cout<<"Enter the string";
    cin>>s;

    longest_substring(s);

    return 0;
}