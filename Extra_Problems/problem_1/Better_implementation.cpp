#include <bits/stdc++.h>
using namespace std;

int largest_sum_of_weights(int N, vector<int>& A, vector<int>& B) {
    // Create a map to count the frequency of each vertex in the edges
    map<int, int> frequency;
    for (int i = 0; i < A.size(); ++i) {
        frequency[A[i]]++;
        frequency[B[i]]++;
    }

    // Create a vector of pairs (vertex, frequency) and sort it based on frequency
    vector<pair<int, int>> vertices;
    for (auto& entry : frequency) {
        vertices.push_back({entry.second, entry.first});
    }
    sort(vertices.rbegin(), vertices.rend());

    // Assign values to vertices according to their frequency
    map<int, int> value;
    int val = N;
    for (auto& vertex : vertices) {
        value[vertex.second] = val--;
    }

    // Calculate the sum of weights of the edges
    int sum = 0;
    for (int i = 0; i < A.size(); ++i) {
        sum += value[A[i]] + value[B[i]];
    }

    return sum;
}

int main() {
    int N, M;
    cout << "Enter the number of vertices in the graph: ";
    cin >> N;
    cout << "Enter the number of edges in the graph: ";
    cin >> M;

    vector<int> A(M), B(M);
    cout << "Enter the elements of the array A: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Enter the elements of the array B: ";
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int sum = largest_sum_of_weights(N, A, B);
    cout << "The maximum sum of weights is: " << sum << endl;

    return 0;
}
