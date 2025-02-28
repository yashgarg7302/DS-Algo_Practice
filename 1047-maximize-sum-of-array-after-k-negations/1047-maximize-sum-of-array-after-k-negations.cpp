class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        while(k){
        sort(nums.begin(),nums.end());
        nums[0] *= -1;
        k--;
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += nums[i];
        }
        return ans;
    }
};