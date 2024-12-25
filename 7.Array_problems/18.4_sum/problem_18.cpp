//THis problem can be solved by exptending the 2sum peroblem and where the two elements ar fixed an the other two are calculated until all the numbers 
//are found this is dine usng the hashmaps

//
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


vector<vector<int>> four_sum(vector<int> nums, int target){
    
    vector<vector<int>> result;
    //Step 1: Sort the array
    sort(nums.begin(), nums.end());
    int n = nums.size();

    //Step 2: Skip the duplicates of the first element
    for(int i = 0; i<n-3; i++){
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
    //Step 3: Skip the duplicates of the second element
        for(int j=i+1; j<n-2; j++){
            if(j>i+1 && nums[j] == nums[j-1]){
                continue;
            }

            //Step 4: Get the thrid and the fourth element
            int c = j + 1;
            int d = n - 1;

            while (c < d){
                long long current_sum = (long long) nums[i] + nums[j] + nums[c] + nums[d];

                if(current_sum == target){
                    result.push_back({nums[i], nums[j], nums[c], nums[d]});
                    while(c<d && nums[c] == nums[c-1]){
                        c++;
                    }
                    while(c<d && nums[d] == nums[d-1]){
                        d--;
                    }

                    c++;
                    d--;

                }

                else if( current_sum < target){
                    c++;
                }
                else{
                    d--;
                }

            }
        }

        
    }

    for(const auto& vec : result){
        cout << "The required vector elements are: ";
        for(const auto& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }

    return result;


}


int main(){

    vector<int> nums;
    int n;
    int target;
    int ele;

    cout<<"Enter the no.og elements of the array:";
    cin>>n;

    cout<<"Enter the elements of the array:";
    for(int i = 0 ; i<n; i++){
        cin>>ele;
        nums.push_back(ele);
    }

    cout<<"Enter the target value :";
    cin>>target;

    four_sum(nums, target);
    return 0;
}