#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX
#include <algorithm> // For std::min

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s; // Number of numbers, objective number.
    cin >> n >> s;

    vector<int> nums(n); // Initialize the vector with size n

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int initial_sum = 0;
    for (int num : nums) {
        initial_sum += num;
    }
    if (initial_sum < s) {
        cout << 0;
        return 0;
    }

    int start = 0, end = 0;
    int curr_sum = 0;
    int min_length = INT_MAX;

    while (end < n) {
        curr_sum += nums[end++];

        while (curr_sum >= s) {
            min_length = min(min_length, end - start);
            curr_sum -= nums[start++];
        }
    }

    if (min_length == INT_MAX) {
        cout << 0; // No valid subarray found
    } else {
        cout << min_length;
    }

    return 0;
}
