
/*Naive implementation (It has a time complexity of o(ologn))*/
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int solution(int arr[], int n){
//     int com_num = 0;
//     int highest = 0;
//     int lowest = 0;
//     map<int,int> mpp;

//     for (int i = 0; i< n; i++){
//         mpp[arr[i]]++;
//     }

//     for(auto it:mpp){
//         cout<<it.first<<"  "<<it.second<<endl;
//     }

//     for(auto it:mpp){
//         if(it.second > com_num){
//             com_num = it.second;
//             highest = it.first;

//         }
//     }

//     cout<<"The highest frequency digit is :"<<highest<<endl;

//     for(auto it:mpp){
//         if(it.second < com_num){
//             com_num = it.second;
//             lowest = it.first;

//         }
//     }

//     cout<<"The lowest frequency digit is :"<<lowest;
// }


// int main(){
//     int arr[1000],n;


//     cout<<"Enter the no.of elements of the array :";
//     cin>>n;

//     cout<<"Enter the elements of the array : ";
//     for(int i = 0; i< n; i++){
//         cin>>arr[i];
//     }

//     solution(arr, n);
// }



/*Slightly modified implementation with less for loops (The timecomplexity still remains the same as the dominant terms of the map creation and the traversal are still the same)*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solution(int arr[], int n){
    int max_frequency = 0;
    int min_frequency = n;
    int highest = 0;
    int lowest = 0;
    map<int,int> mpp;

    for (int i = 0; i< n; i++){
        mpp[arr[i]]++;
    }

    // for(auto it:mpp){
    //     cout<<it.first<<"  "<<it.second<<endl;
    // }

    for(auto it:mpp){
        if(it.second > max_frequency){
            max_frequency = it.second;
            highest = it.first;

        }
        if(it.second < min_frequency){
            min_frequency = it.second;
            lowest = it.first;

        }
    }

    cout<<"The highest frequency digit is :"<<highest<<endl;
    cout<<"The lowest frequency digit is :"<<lowest;
}


int main(){
    int arr[1000],n;


    cout<<"Enter the no.of elements of the array :";
    cin>>n;

    cout<<"Enter the elements of the array : ";
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }

    solution(arr, n);
}