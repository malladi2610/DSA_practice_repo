
/*An Armstrong number (also known as a narcissistic number) is a number that is the sum of its own digits each raised to the power of the number of digits in the number. This definition typically applies to positive integers. For example, a 3-digit number is an Armstrong number if the sum of the cubes of its digits is equal to the number itself.

Here are the characteristics of Armstrong numbers:
- They can be found in any number of digits.
- For a number with \(n\) digits \(a_1, a_2, ..., a_n\), the number is an Armstrong number if:
\[a_1^n + a_2^n + ... + a_n^n = \text{original number}\]

Examples:
- \(153\) is an Armstrong number because \(1^3 + 5^3 + 3^3 = 153\).
- \(9474\) is an Armstrong number because \(9^4 + 4^4 + 7^4 + 4^4 = 9474\).

Would you like to know how to find Armstrong numbers within a certain range, or do you have a specific number in mind to check if it's an Armstrong number?*/

#include<iostream>
#include<math.h>
using namespace std;

int solution(int arr[], int digits){
    int arm_no = 0, x = 0;
    for(int i = 0; i<digits; i++){
        x = x + pow(arr[i],digits);
    }

    return x;
}

int main(){
    int n = 0, digits = 0, arr[1000] = {0}, i = 0, arm_no = 0, t = 0;
    bool ans;
    cout<<"Enter the number to compute the Armstrong : ";
    cin>> n;

    t = n;

    while(n!=0){
        int p = n % 10;
        arr[i] = p;
        digits = digits + 1;
        i = i + 1;
        n = n/10;
    }

    cout<<"The number of digits in the given number : "<<digits<<endl;

    for(int k = 0; k<digits; k++){
        cout<<"The digits of the given number are : "<<arr[k]<<endl;
    }

    arm_no = solution(arr,digits);
    
    ans = arm_no == t ? true : false;

    cout<<"The final conlusion : "<<ans<<endl;

}
