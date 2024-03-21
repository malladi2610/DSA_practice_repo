#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solution(int k, int A[], int n){

    int p = 0;
    int count_arr[1000];
    for(int i = 0; i< n; i++){
        int count = 1;

        while (i < n-1 && A[i] == A[i+1]){
            i++;
            count++;
        }
        count_arr[p] = count; 
        cout<<A[i]<<":"<<count<<endl;
        p = p + 1;
    }



    sort(count_arr, count_arr+k);
        for(int i = 0; i<p; i++){
        cout<<count_arr[i];
    }
    int second_largest = count_arr[-2] + k;

    cout<<second_largest;
    return second_largest;
}

int main(){
    int k = 0,sol = 0,n = 0;
    int A[1000];

    cout<<"Enter the no.of elements of array of nail heights: ";
    cin>>n;

    for(int i = 0; i<n;i++){
        cin>>A[i];
    }

    sol = solution(k,A, n);
    cout<<"Maximal number of nails at the smae height :"<<sol;


}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(int k, int A[], int n) {
    int maxNails = 0; // This will hold the maximum number of nails at the same height.
    int start = 0; // Start of the current window.

    for(int end = 0; end < n; ++end) {
        // Expand the window to include as many nails as possible within the limit of hammering k nails down.
        while (start < end && A[end] - A[start] > k) {
            // This nail can't be hammered down to match the start nail height within k hammerings.
            // So we need to move the start of the window forward.
            start++;
        }
        // Calculate the number of nails in the current window.
        maxNails = max(maxNails, end - start + 1);
    }
    return maxNails;
}

int main() {
    int k, n;
    cout << "Enter the no. of elements in the array of nail heights: ";
    cin >> n;
    cout << "Enter the max number of nails you can hammer down: ";
    cin >> k;
    int A[10000]; // Adjusted the size according to the problem constraints.

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int sol = solution(k, A, n);
    cout << "Maximal number of nails at the same height: " << sol << endl;
    return 0;
}

