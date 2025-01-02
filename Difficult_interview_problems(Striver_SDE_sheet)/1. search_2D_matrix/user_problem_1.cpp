#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search_2D_matrix(vector<vector<int>> &matrix, int k){
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;
    int high = m*n-1;

    while(low <= high){
     int mid = low + (high - low)/2;
    

    //The reason why this above formula work is this reason
    /*In a 2D matrix with `m` rows and `n` columns, elements are often stored in a 1D array in row-major order. This means that the element at position `(i, j)` in the 2D matrix corresponds to the position `i * n + j` in the 1D array.

When performing a binary search on this matrix, you treat it as a 1D array with `m * n` elements. The midpoint index `mid` is calculated as `low + (high - low) / 2`. To map this 1D index back to 2D coordinates, you use the formulas:

- `row = mid / n`
- `col = mid % n`

**Explanation:**

- **Row Calculation (`row = mid / n`):**
  - Integer division of `mid` by `n` gives the number of complete rows that fit into the first `mid` elements.
  - For example, if `mid = 7` and `n = 3`, then `7 / 3 = 2`, indicating that the 7th element is in the 2nd row (0-indexed).

- **Column Calculation (`col = mid % n`):**
  - The remainder when `mid` is divided by `n` gives the position within the row.
  - Continuing the example, `7 % 3 = 1`, indicating that the 7th element is in the 1st column of the 2nd row.

These calculations effectively reverse the mapping from 2D to 1D, allowing you to locate the element's position in the 2D matrix based on its index in the 1D representation.

This method is commonly used in algorithms that perform binary search on matrices, as it allows efficient access to elements without explicitly converting the entire matrix into a 1D array. */
     int row = mid/n;
     int col = mid%n;

     if(matrix[row][col] == k){
        cout<<"true";
        return true;
     }

     else if(matrix[row][col] < k){
        low = mid + 1; //THis indicates that the no. is present in the other half and not in the first half
     }
     else{
        high = mid - 1; //THis indicates that the no. is present in the previous half and not in the other half
     }

    }
    cout<<"false";    
    return false;

}

int main(){
    int m, n, k, ele;
    vector<vector<int>> matrix;

    cout<<"Enter the no.of rows";
    cin>> m;
    cout<<"Enter the no.of columns";
    cin>>n;
    cout<<"Enter the elements of the matrix";
        for(int i = 0; i<m; i++){
            vector<int> row;
            for(int j = 0; j<n; j++){
                cin>>ele;
                row.push_back(ele);
            }
            matrix.push_back(row);
        }
    cout<<"Enter the target element ";
    cin>>k;

    search_2D_matrix(matrix, k);
    return 0;
}
