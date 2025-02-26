class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    int sum1 = 0;        
    int sum2 = 0;        
    int ans = 0;        
    for (int i=0;i<n;i++) {
        sum1 = max(0, sum1 + nums[i]);
        sum2 = min(0, sum2 + nums[i]);
        ans = max(ans, max(sum1, abs(sum2)));
    }
    return ans;
    }
};