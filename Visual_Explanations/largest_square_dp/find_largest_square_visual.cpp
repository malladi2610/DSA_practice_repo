#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int find_largest_square(vector<vector<int>> matrix)
{
    int n = matrix.size();
    if (n == 0) {
        return 0;
    }

    int m = matrix[0].size();
    if (m == 0) {
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSize = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    int top = dp[i - 1][j];
                    int left = dp[i][j - 1];
                    int diagonal = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min(top, min(left, diagonal));
                }

                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }

    return maxSize;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0}
    };

    cout << "Largest square size is: " << find_largest_square(matrix) << '\n';
    return 0;
}

