#include<iostream>
using namespace std;
/*This code is similar to the pattern 3, but instead of repeating the 
pattern of 1 to n for each line there is a continous increment of the numbers
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

The logic is as follows
*/

int main(){
    int n = 0;
for(int i = 1; i<=5; i++){
    for(int j = 1; j<=i; j++){
        n = n + 1;
        cout<<n<<" ";
    }
    cout<<"\n";
}
}