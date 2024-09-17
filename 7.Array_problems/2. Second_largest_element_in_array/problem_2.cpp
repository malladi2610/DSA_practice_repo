#include<iostream>
using namespace std;

void second_element(int arr[], int n){
    int largest = 0;
        int second_largest = 0;
        if(n == 1){
            cout<<"Second_largest number doesn't exist";
        }
        for(int i = 0; i<n; i++){
            if(arr[i] > largest){
                second_largest = largest;
                largest = arr[i];
            }
            else if(arr[i] > second_largest && largest != arr[i]){
                second_largest = arr[i];
            }
            else if(second_largest == 0){
               cout<<"Second_largest number doesn't exist";
            }
            
            // else{
            //     return -1;
            // }
        }
    cout<<"The second largest element in the array is "<<second_largest;
}

int main(){
    int n, arr[100];

    cout<<"Enter the no.of elements of the array :";
    cin>>n;
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }

    second_element(arr,n);
}