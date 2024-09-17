#include<iostream>

using namespace std;


int selection_sort(int n, int arr[]){
    
    for(int i = 0; i<=n-2; i++){
        int mme = i; //This is the minimum element index
        for(int j = i; j<=n-1; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"The sorted array"<<endl;
    for(int i = 0; i<n;i++){
        cout<<arr[i];
    }
}

int main(){
    int n, arr[1000];
    cout<<"Enter the no.of elements of the array";
    cin>>n;

    cout<<"Enter the elements of the array";
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    selection_sort(n,arr);
}