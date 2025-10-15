class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
    if (n < 2) return 0;

    vector<int> inc_left(n, 1), inc_right(n, 1);

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1])
            inc_left[i] = inc_left[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1])
            inc_right[i] = inc_right[i + 1] + 1;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int k = min(inc_left[i], inc_right[i + 1]);
        ans = max(ans, k);
    }

    return ans;
    }
};