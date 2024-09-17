// #include<iostream>
// using namespace std;
// void repeat_cleaner(int arr[], int n){

//     for(int i = 0; i<n; i++){
//         int count = 0;
//         int ele = arr[i];
//         for(int j = 0; j<n;j++){
//             if (arr[ele] == arr[i]){
//             count = count + 1;
//             }
//         }
//         cout<<count;
//         if(count > 1){
//             for(int k = 1; k<count;k++){
//                 cout<<"Before: ";
//                 cout<<arr[ele + k]<<endl;
//                 cout<<arr[ele + count - 1 + k];
//                 arr[ele + k] = arr[ele + count - 1 + k];  
//                 cout<<"After: "<< arr[ele + k]<<endl;
//             }
//         }    
//     }

//     int size_arr = sizeof(arr)/sizeof(int);
//     for(int i = 0; i<size_arr; i++){
//         cout<<"The elements of the arr are : "<<arr[i];
//     }

// }

// void selection_sort(int arr[], int n){
//     for(int i = 0; i<n-1; i++){
//         int mme = i;
//         for(int j = i; j<n;j++){
//             if(arr[j] < arr[i]){
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             }
//         }
//     }
//     cout<<"The sorted array"<<endl;
//     for(int i =0; i<n; i++){
//         cout<<arr[i];
//     }
//     repeat_cleaner(arr,n);

// }

// int main(){
//     int arr[100] = {0}, n=0;

//     cout<<"Enter the no.of elemets of the array : ";
//     cin>>n;

//     for(int i = 0; i< n; i++){
//         cin>>arr[i];
//     }

//     selection_sort(arr,n);
// }

#include<iostream>
using namespace std;

int repeat_cleaner(int arr[], int n){

    if(n == 0){
        return 0;
    }
    int unique_elements = 1;



    for(int i = 1; i<n; i++){
        if(arr[i] != arr[i-1]){
            arr[unique_elements] = arr[i];
            unique_elements++;
        }
    }

    return unique_elements;
}

void selection_sort(int arr[], int n){
    for(int i = 0; i<n - 1 ; i++){
        int mme = i;
        for (int j = i + 1; j < n; j++){
            if(arr[j] < arr[mme])
            mme = j;
        }

        int temp = arr[i];
        arr[i] = arr[mme];
        arr[mme] = temp;

    }

    cout<<"The sorted array: ";
    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;

}


int main(){
    int arr[100], n;

    cout<<"Enter the no.of elements of the array";
    cin>>n;

    cout<<"Enter the elements of the array";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    selection_sort(arr,n);


    int unique_elements = repeat_cleaner(arr,n);

    for(int i = 0; i<unique_elements;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"The number of unique elements of the array"<<unique_elements;
}