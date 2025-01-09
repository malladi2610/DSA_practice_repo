#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarraysWithXOR(vector<int>& A, int B) {
    unordered_map<int, int> freq;
    int prefixXOR = 0;
    int count = 0;

    for (int num : A) {
        // Update the prefix XOR
        prefixXOR ^= num;

        // Check if the prefix XOR equals B
        if (prefixXOR == B) {
            count++;
        }

        // Check if prefixXOR ^ B exists in the map
        if (freq.find(prefixXOR ^ B) != freq.end()) {
            count += freq[prefixXOR ^ B];
        }

        // Update the frequency of prefixXOR
        freq[prefixXOR]++;
    }

    return count;
}

int main() {
    int n, B;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter the value of B: ";
    cin >> B;

    int result = countSubarraysWithXOR(A, B);
    cout << "Total number of subarrays with XOR equal to " << B << ": " << result << endl;

    return 0;
}
