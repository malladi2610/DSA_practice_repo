#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string solution(vector<string>& strs){
string output,x,y;
int smallest_str_len = strs[1].length();

for(int i = 1; i<strs.size();i++){
    if(strs[i].length() < smallest_str_len){
        smallest_str_len = strs[i].length();
    }
}

//1. The code should only work for the longest string and not the common characters (line 24)
//2. The code should only interate till the last element and should stop after that and not try to go out of bound (line 21)
for(int i = 0; i<strs.size();i++){
    for(int j = 0; j<smallest_str_len;j++){
        if(i == strs.size() -  1){
            x = strs[i];
            y = strs[0];
        }
        else{
            x = strs[i];
            y = strs[i+1];
        }


        if(x[j] == y[j]){
            if(output.find(x[j]) > 0){
                break;
            }
            output.append(1, x[j]);
        }
        else{
            break;
        }
    }
}

return output;

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