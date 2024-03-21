#include<iostream>
using namespace std;

void solution(int n, int i){
    
    if(n == 0){
        return;
    }

    cout<<"The number is :"<<n<<endl;
    solution(n-1,i-1);



}

int main(){
    int n = 0,i = 1;

    cout<<"Enter the no.of iteration";
    cin>>n;


    solution(n,i);
}