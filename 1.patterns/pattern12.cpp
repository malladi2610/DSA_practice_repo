#include<iostream>
using namespace std;

/*The following pattern needs to be generated 
1      1
12    21
123  321
12344321

The no.of rows will be equal to the 4 as visible from the pattern  and the gap b/w the no's is starting from 6 and decreasing by 2, 2*4-2*/
int main(){
int n = 4;
for (int i = 1; i<=4; i++){
    //Numbers
    for(int j = 1; j<=i; j++){
        cout<<j;
    }
    //Space
    for(int k = 1; k<=2*n-2;k++){
        cout<<" ";
    }
    //Numbers
    for(int j = i; j>=1; j--){
        cout<<j;
    }
    n = n - 1;
    cout<<endl;
}
}