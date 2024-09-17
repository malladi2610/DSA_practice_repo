#include<iostream>
using namespace std;

void isrotateandsorted(int arr[], int n){
    int break_point = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] > arr[(i+1)%n]){
            break_point++;
        }

    }
    if(break_point <= 1){
        cout<<"The array is rotate and sorted";
    }

    else{
        cout<<"The array is not rotate and sorted";
    }
}

void sorting_checker(int arr[], int n, int order){
    bool sorted = true;
    
    if (order == 1){
    for(int i = 0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            sorted = false;
            break;
            
        }
    }
    cout<<(sorted? "The array is sorted in the increasing order":"The array is not sorted");
    }

    else{
         for(int i = 0; i<n-1; i++){
        if(arr[i] < arr[i+1]){
            sorted = false;
            break;
        }
    }
    cout<<(sorted? "The array is sorted in the decreasing order":"The array is not sorted");
    }

}

int main(){
    int arr[100] = {0}, n, order;

    cout<<"Enter the no.of elements of the array :";
    cin>>n;

    // Read array elements
    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

cout << "Enter the order to check in:\n"
        "1. For Increasing order - 1\n"
        "2. For Decreasing order - 2\n"
        "3. For Rotated sorted check(Only for incresing order) - 3\n";
cin>>order;

    switch(order){
        case 1: sorting_checker(arr,n,1);
        break;
        case 2: sorting_checker(arr,n,2);
        break;
        case 3: isrotateandsorted(arr, n);
        break;
        default: cout<<"Invalid case";
        break;
    }
    return 0;



}

