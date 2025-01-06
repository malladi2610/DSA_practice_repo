#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    // Step 1: Initialize the DP array with all 1s
    vector<int> dp(n, 1);

    // Step 2: Iterate through each row, starting from the second row
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1]; // Update dp[j]
        }
    }

    // Step 3: Return the bottom-right value
    return dp[n - 1];
}

int main() {
    int m, n;

    cout << "Enter the number of rows (m): ";
    cin >> m;

    cout << "Enter the number of columns (n): ";
    cin >> n;

    int result = uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
