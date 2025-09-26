class Solution {
public:
    int triangleNumber(vector<int>& nums) {
         int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int k = n - 1; k >= 2; k--) {
            int left = 0, right = k - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[k]) {
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }
        return count;
    }
};