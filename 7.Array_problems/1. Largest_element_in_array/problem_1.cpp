#include<iostream>
using namespace std;

void largest_number(int arr[], int n){
    int largest = 0;
        if (n == 1){
            largest = arr[0];
        }
    for(int i = 0; i<n ; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    cout<<"The largest number of the given array is :"<<largest;

}

int main(){
    int n, arr[100];
    cout<<"Enter the no.of elements of the array : ";
    cin>>n;
    cout<<"The elements of the array are :";
    for(int i = 0; i<n;i++){
        
        cin>>arr[i];
    }

    largest_number(arr, n);
    return 0;
}