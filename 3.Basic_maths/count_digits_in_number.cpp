/*
Complexity analysis: 
a) Time complexity: O(log10(n))
b) Space complexity: O(1) */

#include<iostream>
#include<string>
using namespace std;

// int main(){
//     int n, count = 0;
//     cout<<"Enter a number: ";
//     cin>>n;
//     while(n > 0){
//         if(n%10 >= 0){
//             count++;
//             n = n/10;
//         }
//     }

//     cout<<"The no.of digits are:"<<count;

//     return 0;
// }


/*Convert the integer to a string*/
/*
Time_compexity: O(1)
Space_complexity: O(1)*/
int main(){
    int n, count = 0;
    cout<<"Enter a number: ";
    cin>>n; 

    string n_string = to_string(n);

    cout<<"No.of digits are : "<<n_string.length();

    return 0;

}

/*Use logarithmic scale*/

