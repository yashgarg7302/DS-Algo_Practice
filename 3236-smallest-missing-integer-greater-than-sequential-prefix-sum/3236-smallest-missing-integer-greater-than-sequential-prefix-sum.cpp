class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1]+1 == nums[i]) sum += nums[i];
            else break;
        }
         while (true) {
            if (seen.count(sum) == 0) return sum;
            sum++;
        }
       return sum;
    }

};