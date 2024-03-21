#include<iostream>
using namespace std;

/*
The following pattern needs to be generated 
1
10
101
0101
10101

To develop a patern like this the following strategy can be applied, it has 5 roows and the columns are dependede on the row, the value might be incremented by 1 and dcremented b1
*/
int main(){
    int n = 1;
    for(int i = 0; i<5; i++){
        if(i%2 == 0){
            n = 1;
        }
        else{
            n = 0;
        }
        for(int j = 0; j<=i; j++){
            cout<<n;
            n = 1 - n;

        }
        cout<<"\n";
    }
}