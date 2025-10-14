class Solution {
public:
    bool isIncreasing(const vector<int>& nums, int start, int k) {
    for (int i = start; i < start + k - 1; ++i) {
        if (nums[i] >= nums[i + 1])
            return false;
    }
    return true;
}

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    for (int a = 0; a <= n - 2 * k; ++a) {
        if (isIncreasing(nums, a, k) && isIncreasing(nums, a + k, k))
            return true;
    }
    return false;
}
};