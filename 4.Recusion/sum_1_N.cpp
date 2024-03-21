#include<iostream>
using namespace std;


void solution(int n, int sum){
  
    if(n == 0){
        cout<<"The total sum of the given iterations are :"<<sum;
        return;
    }

    sum = sum + n;
    solution(n-1,sum);
}

int main(){
    int n = 0, sum = 0;

    cout<<"Enter the no.of iterations of addition";
    cin>>n;


    solution(n, sum);
}