class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
          int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] <= 0 || nums[i] > n)
            nums[i] = n + 1;
    }

    for (int i = 0; i < n; i++) {
        int x = abs(nums[i]);
        if (x >= 1 && x <= n && nums[x - 1] > 0)
            nums[x - 1] = -nums[x - 1];
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0)
            return i + 1;
    }
    return n + 1;
    }
};