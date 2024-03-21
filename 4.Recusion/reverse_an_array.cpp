

#include<iostream>
using namespace std;

void solution(int arr[], int start, int end){
    if (start >= end){
        return;
    }
  
    int temp = arr[end];
    arr[end] = arr[start];
    arr[start] = temp;

    solution(arr, start + 1, end - 1);
}

int print_array(int n, int arr[]){
        cout<<"The array is:";
    for(int i = 0; i<n; i++){
        cout<<"The elements of the array are: "<<arr[i]<<endl;
    }
}

int main(){
    int n, r_arr[1000] = {0}, arr[1000] = {0}, start = 0, end = 0;
    cout<<"Enter the number of elements of the array:";
    cin>>n;


    cout<<"Enter the elements of the array:";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The start of the element: ";
    cin>>start;

    cout<<"The end of the element: ";
    cin>>end;

    print_array(n,arr);


    solution(arr, start,end);

    print_array(n,arr);

    // while(n != 0){
    //     remainder = n % 10;
    //     reversed_number = reversed_number*10 + remainder;
    //     n /= 10;

    // }
    // cout<<reversed_number;


}