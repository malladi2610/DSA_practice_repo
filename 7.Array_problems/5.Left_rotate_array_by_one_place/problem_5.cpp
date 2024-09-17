#include<iostream>
using namespace std;

void left_shift(int arr[], int n){
    int temp;
     temp = arr[0];
    for(int i = 0; i<n;i++){
        if(i == n-1){
            arr[i] = temp;
            break;
        }
       arr[i] = arr[i+1];
    }

    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    int n;
    int arr[1000];
    cout<<"Enter the no.of elements of the array";
    cin>>n;

    cout<<"Enter the elements of the array";
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }

    left_shift(arr,n);
}