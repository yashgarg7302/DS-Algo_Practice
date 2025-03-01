class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                nums[i - 1] = nums[i - 1] * 2;
                nums[i] = 0;
            }
        }
        int nonZeroIndex = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];
            }
        }
        while (nonZeroIndex < n) {
            nums[nonZeroIndex++] = 0;
        }

        return nums;
    }    
    };