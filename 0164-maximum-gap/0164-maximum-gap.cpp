class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            int num = nums[i] - nums[i-1];
            ans = max(ans,num);
        }
        return ans;
    }
};