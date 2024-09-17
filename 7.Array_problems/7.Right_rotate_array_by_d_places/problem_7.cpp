#include<iostream>
using namespace std;

void right_shift(int arr[], int n){
    int temp;
    temp = arr[n-1];
    for(int i = n-1; i>=0;i--){
        if(i == 0){
            arr[i] = temp;
            
            break;
        }
       arr[i] = arr[i-1];
       //cout<<"The element position {}"<<K+1;
       
    }

    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    int n;
    int arr[1000];
    int shift;
    cout<<"Enter the no.of elements of the array";
    cin>>n;

    cout<<"Enter the elements of the array";
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the no.of shifts";
    cin>>shift;

    for(int i =1 ; i<=shift; i++){
        right_shift(arr,n);
        cout<<endl;
    }
    
}

// This above appraoch fails when the values of k is 