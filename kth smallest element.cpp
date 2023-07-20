#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthSmallest(const vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int n: a) {
        minHeap.push(n);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {
    int n, k;

    cout << "Enter the size of the array and the value of K: ";
    cin >> n >> k;

    if (n <= 0 || k <= 0 || k > n) {
        cout << "Invalid input.";
        return 1;
    }

    vector<int> a(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b = findKthSmallest(a, k);
    cout << "The " << k << "th smallest element is: " << b << "\n";

    return 0;
}
