#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string solution(vector<string>& strs){
// string output,x,y;

// if(strs.empty() == 1){
//     return "";
// }

// int smallest_str_len = strs[0].length();

// for(int i = 1; i<strs.size();i++){
//     if(strs[i].length() < smallest_str_len){
//         smallest_str_len = strs[i].length();
//     }
// }

// //1. The code should only work for the longest string and not the common characters (line 24)
// //2. The code should only interate till the last element and should stop after that and not try to go out of bound (line 21)
// for(int i = 0; i<strs.size();i++){
//     for(int j = 0; j<smallest_str_len;j++){
//         if(i == strs.size() -  1){
//             x = strs[i];
//             y = strs[0];
//         }
//         else{
//             x = strs[i];
//             y = strs[i+1];
//         }


//         if(x[j] == y[j]){
//             if(output.find(x[j]) > 0){
//                 break;
//             }
//             output.append(1, x[j]);
//         }
//         else{
//             break;
//         }
//     }
// }

// return output;

 if(strs.empty()) return ""; // If the vector is empty, return an empty string.

    string prefix = strs[0]; // Assume the first string is the common prefix.

    for(int i = 1; i < strs.size(); i++) {
        while(strs[i].find(prefix) != 0) { // the find() function returns anything greater than 0, if the required prefix is not found
            prefix = prefix.substr(0, prefix.size() - 1); //It means start from 0 and then reduce by one character, if the whole prefix is not the common one.
            if(prefix.empty()) return ""; // If the prefix is reduced to an empty string, return "".
        }
    }

    return prefix;

}


int main(){
    vector<string> strs;
    string s, output;
    int n;

    cout<<"Enter the no.of elements of the vector"<<endl;
    cin>>n;

    for(int i = 0; i< n;i++){
        cin>>s;
        strs.push_back(s);
    }

    for(int i = 0; i<n; i++){
        cout<<strs[i];
    }


    output = solution(strs);

    cout<<"The common string in the given vector is"<<output;

    return 0;

}