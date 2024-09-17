// #include<iostream>
// using namespace std;

// void shifting_zeros(int arr[], int n){
//     //I think this is similar to sorting (Basic selection sort logic of swapping)
//     int temp = 0;
//     if(n == 1){
//         cout<<arr[0];
//     }

//     for(int i = 0; i<n; i++){
//         if(arr[i] == 0){
//         for(int j = i + 1; j < n; j++){
//             if(arr[j] == 0){
//                 j = j + 1;
//             }
//             if(j == n){
//                 break;
//             }
//             cout<<arr[j]<<" ";
//             cout<<endl;
//             temp = arr[j];
//             cout<<arr[i]<<" ";
//             cout<<endl;
//             arr[j] = arr[i];
//             arr[i] = temp;
//             break;
//         }
//         for(int i = 0; i<n; i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//         }  
//     }

//     for(int i = 0; i< n; i++){
//         cout<<arr[i];
//     }
// }

// int main(){
//     int n, arr[100];

//     cout<<"Enter the no.of elements of the array: ";
//     cin>>n;

//     for(int i = 0 ; i < n ;i++){
//         cin>>arr[i];
//     }

//     shifting_zeros(arr,n);
// }


#include<iostream>
using namespace std;

void shifting_zeros(int arr[], int n){
    //I think this is similar to sorting (Basic selection sort logic of swapping)
    int temp = 0;
    if(n == 1){
        cout<<arr[0];
    }

    for(int i = 0; i<=n; i++){
        if(arr[i] == 0){
        for(int j = i + 1; j < n; j++){
            if(arr[j] == 0){
                j = j + 1;
            }
            if(j == n){
                break;
            }
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            break;
        } 
        }
    }
    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n, arr[100];

    cout<<"Enter the no.of elements of the array: ";
    cin>>n;

    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }

    shifting_zeros(arr,n);
}