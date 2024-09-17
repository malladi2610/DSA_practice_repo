#include<iostream>
using namespace std;

bool sort_checker(int n, int arr[]){
/*1. There needs to be two checks performend that counts the no.of breaks
if the no.of breaks are > 1 then the array is not sorted in the increasing order
1.1. A break is counted with just comparing the two elements to one another and they should all be in increasing order (break starts with  0 and increments)
1.2. A end to start continutiy check is performed with the first and the last element of the array as the increasing order needs to be valid even after the rotations is performed*/
int break_counter = 0;
for (int i =0 ; i<n-1; i++){
    if(arr[i] > arr[i+1]){
        break_counter = break_counter + 1;
    }
}
    if(arr[n-1] > arr[0]){
        break_counter = break_counter + 1;
    }


if (break_counter > 1){
    return false;
}
else{
    return true;
}

}

int main(){
    int n,arr[100];

    cout<<"Enter the no.of elements of the array :";
    cin>>n;

    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }

   if( sort_checker(n, arr)){
    cout<<"The array is sorted perfectly";
   }
   else{
    cout<<"The array is not sorted correctly";
   }

    return 0;
}