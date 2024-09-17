/*This sorting technique is into the existanece as the previous sorting techniques like the selection, Insertions and the bubble sorting techniques have a time complexity of O(n2)*/

/*Merge sort - Works on the principle of divide and merge*/

/*Algorithm
1. There will be an arr, low = 0 and high = n as the input variables for the merge sort function
2. Take the array and break it into two parts and the point at where it can be divided can be found by the mid = (low + high)/2 and this will be passed to the merge_sort function again. merge_sort(arr, low, mid);, 
merge_sort(arr, mid + 1, high);
3. Base case: if(low >= high) return; 
4. The merge function is as follows
temp = []
left = low
right = mid + 1
while( left <= mid && right < = high){
    if(arr[left] <= arr[right]){
        temp.add(arr[left])
        left ++
    }
    else
        temp.add(arr[right])
} 
while(left <= mid){
    temp.add(arr[left])
    left ++;
}
while(right <=high){
    temp.add(arr[right])
    right++;
}
for ( i = 0 to high){     
    arr[i] = temp[i - low];     ----> Need to verify this.
}
*/



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &arr, int low, int mid,int high){
    vector<int> temp;

    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
        }
        else{
            temp.push_back(arr[right]);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high; i++){
        arr[i] = temp[i - low];
    }

    return arr;
}

void mS(vector<int> &arr, int low, int high){
    vector<int> result;
    if(low >= high)
    return;

    int mid = (low + high)/2;

    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    result = merge(arr, low, mid ,high);

    cout<<"The final sorted vector is :";
    for(int i = 0; i<=high; i++){
       cout<<result[i]; 
    }

}

void merge_sort(vector<int> & arr, int n){
    mS(arr, 0, n-1);

}
int main(){
    int n;
    int x;
    vector<int> arr;

    cout<<"Enter the number of elements of the array :";
    cin>>n;
    cout<<"Enter the elements of the array";
    for(int i = 0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }

    merge_sort(arr, n);


}