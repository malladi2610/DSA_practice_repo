#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//In this function the two halves are being merged
int merge(vector<int> &nums, int start, int mid, int end){
    cout<<"Entered the merge";
    vector<int> temp;
    int i = start;
    int j =  mid + 1;

    //Pointer i takes care of the variables until mid and the j from mid to end
    while(i <= mid && j<= end){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i]);
            i += 1;
        }
        else{
            temp.push_back(nums[j]);
            j += 1;
        }
    }
    //THis block is to take care of the case when the split is uneven, if either of the halves are longer
    while(i<= mid){
        temp.push_back(nums[i]);
        i += 1;
    }
    while(j<=end){
        temp.push_back(nums[j]);
         j++;
    }

    for(int k = 0; k<temp.size(); k++){
        nums[start+k] = temp[k];
    }

    return 0;
}

int merge_sort_count(vector<int> &nums, int start, int end){
    cout<<"Entered the merge_sort_count";
    int mid = (start+end)/2;
    int count = 0;

        if (start >= end){
        return 0;
    }

    count += merge_sort_count(nums, start, mid);
    count += merge_sort_count(nums, mid+1, end);

    int j = mid + 1;

    //find reverse pairs across the two halves
    for(int i = start; i<=mid ; i++){
        while ((j<= end) && (nums[i] > 2LL*nums[j]))
        { 

            j += 1;}
        count += (j-(mid + 1));
    }

    merge(nums, start, mid, end);
    return count;


}

int reverse_pairs(vector<int> &nums){
    cout<<"Entered the reverse pair";
    return merge_sort_count(nums, 0, nums.size() - 1);
}

int main(){
    int n, ele;
    vector<int> nums;

    cout<<"Enter the values of no.of elements of the array : ";
    cin>>n;

    cout<<"Enter the value of the elements of the array :";
    for(int i = 0; i< n; i++){
        cin>>ele;
        nums.push_back(ele);
    }


    int result = reverse_pairs(nums);
    cout << "Number of reverse pairs: " << result << endl;
    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// // Merging two sorted halves
// int merge(vector<int>& nums, int start, int mid, int end) {
//     vector<int> temp;
//     int i = start, j = mid + 1;

//     while (i <= mid && j <= end) {
//         if (nums[i] <= nums[j]) {
//             temp.push_back(nums[i]);
//             i++;
//         } else {
//             temp.push_back(nums[j]);
//             j++;
//         }
//     }

//     while (i <= mid) {
//         temp.push_back(nums[i]);
//         i++;
//     }

//     while (j <= end) {
//         temp.push_back(nums[j]);
//         j++;
//     }

//     for (int k = 0; k < temp.size(); k++) {
//         nums[start + k] = temp[k];
//     }

//     return 0;
// }

// // Recursive function to count reverse pairs
// int merge_sort_count(vector<int>& nums, int start, int end) {
//     if (start >= end) return 0;

//     int mid = start + (end - start) / 2;
//     int count = 0;

//     count += merge_sort_count(nums, start, mid);
//     count += merge_sort_count(nums, mid + 1, end);

//     int j = mid + 1;

//     for (int i = start; i <= mid; i++) {
//         while (j <= end && nums[i] > 2LL * nums[j]) {
//             j++;
//         }
//         count += (j - (mid + 1));
//     }

//     merge(nums, start, mid, end);
//     return count;
// }

// int reverse_pairs(vector<int>& nums) {
//     return merge_sort_count(nums, 0, nums.size() - 1);
// }

// int main() {
//     int n, ele;
//     vector<int> nums;

//     cout << "Enter the number of elements in the array: ";
//     cin >> n;

//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> ele;
//         nums.push_back(ele);
//     }

//     int result = reverse_pairs(nums);
//     cout << "Number of reverse pairs: " << result << endl;

//     return 0;
// }
