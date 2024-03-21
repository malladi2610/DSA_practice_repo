#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string string_erase(string &s){
    string result;
    for(auto &x: s){
        if(isalnum(x)){
            result += x;
        }
    }
    return result;
    
}

int verify_string(string &s, int start, int end){
    if(end == -1){
        end = s.length() - 1;
    }

    if(start >= end){
        return 1;
    }

    if(s[start] != s[end]){
        return 0;
    }

    return verify_string(s, start + 1, end - 1);
}

int solution(string &s){
    int ans;

    ans = verify_string(s, 0, -1);

    if(ans == 1){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}

int main(){
    string s;

    cout<<"Enter the string to be verified :";
    getline(cin,s);

    /*Strip the extra characters from the string*/
    s = string_erase(s);

    /*Convert the string to lowercase*/
    for(auto &x : s){
        x = tolower(x);
    }

    // cout<<"The updated string"<<s;

    solution(s);
    

    return 0;

    // cout<<"The verification result"<<ans;

}