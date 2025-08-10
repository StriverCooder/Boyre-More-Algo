#include <bits/stdc++.h>
using namespace std;

// Function to find majority element using Boyer–Moore Majority Vote Algorithm
int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;

    // Step 1: Find candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } 
        else if (num == candidate) {
            count++;
        } 
        else {
            count--;
        }
    }

    // Step 2: Verify candidate (optional, only if you need to check validity)
    count = 0;
    for (int num : nums) {
        if (num == candidate) count++;
    }

    if (count > nums.size() / 2) return candidate; // Majority element exists
    return -1; // No majority element
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);

    if (result != -1) 
        cout << "Majority element is: " << result << endl;
    else 
        cout << "No majority element found." << endl;

    return 0;
}
