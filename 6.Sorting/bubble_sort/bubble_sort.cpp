///
//In this Bubble sort, the swapping happens b/w the adjacent elements and the maximum element is pushed to the ending and this process continues until
//All the elements are not sorted


#include<iostream>
using namespace std;

int bubble_sort(int n, int arr[]){

    for(int i = n - 1; i >= 1; i--){
        for(int j = 0; j<=i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
    cout<<"The sorted elements are :";
    for(int i  = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }

}

int main(){
    int n = 0, arr[1000] = {0};
    cout<<"Enter the no.of elements of the array";
    cin>>n;

    cout<<"Enter the elements of the array";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    bubble_sort(n,arr);
}