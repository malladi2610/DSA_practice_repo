/* Library Functions */
#include <iostream>
#include <vector>
using namespace std;

/* Problem Specific Function */
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftProduct(n, 1);
    vector<int> rightProduct(n, 1);
    vector<int> answer(n);

    // Compute prefix products
    for (int i = 1; i < n; i++) {
        leftProduct[i] = nums[i - 1] * leftProduct[i - 1];
    }

    // Compute suffix products
    for (int i = n - 2; i >= 0; i--) {
        rightProduct[i] = nums[i + 1] * rightProduct[i + 1];
    }

    // Combine prefix and suffix products
    for (int i = 0; i < n; i++) {
        answer[i] = leftProduct[i] * rightProduct[i];
    }

    return answer;
}

/* Main Function */
int main() {
    vector<int> nums;
    int n, ele;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> ele;
        nums.push_back(ele);
    }

    vector<int> result = productExceptSelf(nums);

    cout << "Output: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
