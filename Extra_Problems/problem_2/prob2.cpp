#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// int solution(int k, int A[]){
//     map<int,int> mp;
//     int n = sizeof(A)/sizeof(A[0]);
    
//     for(int i = 0; i<n;i++){
//         mp.insert({A[i], count(A, A+n, A[i])});
//     }

//     cout<< "Elements present in the map: "<<endl;
//     cout<<"key\tElement"<<endl;
//     for(auto it = mp.begin(); it != mp.end(); it++){
//         cout<< it -> first << "\t" << it->second<<endl;
//     }
    
// }

int solution(int K, int A[], int N) {
    int n = N ;
    int best = 0;
    int count = 1;

    for (int i = 0; i < n-K-1; i++) {
        if (A[i] == A[i + 1])
            count = count + 1;
        else
            count = 1;
        if (count > best)
            best = count;
    }
    int result = max(best+K, min(K+1, n));
    
    return result;
}



int main(){
    int n = 0, A[1000] = {0}, k = 0, sol = 0;

    cout<<"Enter the no.of nails atttached to the board : ";
    cin>>n;

    cout<<"Enter the no.of nails to be hammared : ";
    cin>>k;

    cout<<"Enter the height of the nails attached to the board : ";
    for(int i = 0; i < n ; i++){
        cin>>A[i];
    }

    sol = solution(k, A,n);

    cout<<"The maximum frequency of the nails at the same height on the board is : "<<sol;

}


// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<unordered_map>
// using namespace std;

// int findMaxFrequencyWithModifications(vector<int>& heights, int k) {
//     unordered_map<int, int> freqMap;
//     int maxFreq = 0, start = 0, maxLength = 0;

//     for (int end = 0; end < heights.size(); ++end) {
//         // Increase the frequency of the current height
//         freqMap[heights[end]]++;

//         // Update max frequency of any height in the current window
//         maxFreq = max(maxFreq, freqMap[heights[end]]);

//         // If the current window size minus the most frequent element's frequency is greater than k,
//         // it means we cannot make all elements in this window the same with k modifications.
//         // So, we need to shrink the window from the left.
//         while (end - start + 1 - maxFreq > k) {
//             freqMap[heights[start]]--; // Decrease the frequency of the leftmost element
//             start++; // Move the window's left side to the right
//         }

//         // Calculate the maximum length of the window we can achieve
//         maxLength = max(maxLength, end - start + 1);
//     }

//     return maxLength;
// }

// int main() {
//     int n, k;
//     cout << "Enter the number of nails: ";
//     cin >> n;
//     cout << "Enter the number of modifications allowed (k): ";
//     cin >> k;

//     vector<int> heights(n);
//     cout << "Enter the heights of the nails: ";
//     for (int i = 0; i < n; ++i) {
//         cin >> heights[i];
//     }

//     sort(heights.begin(), heights.end()); // Sort the heights for the sliding window approach

//     int result = findMaxFrequencyWithModifications(heights, k);
//     cout << "The maximum number of nails at the same height after at most " << k << " modifications is: " << result << endl;

//     return 0;
// }
