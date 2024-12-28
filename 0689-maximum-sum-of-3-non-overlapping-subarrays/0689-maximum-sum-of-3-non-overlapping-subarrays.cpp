class Solution {
public:
    map<vector<int>,vector<int>>mp;

    vector<int>dp(vector<int>&nums,int rem, int k,int ind){
        if(rem == 0 || ind>=nums.size()){
            return {1,0,-1,-1,-1};
        }

        if(mp.find({rem,ind}) != mp.end()){
            return mp[{rem,ind}];
        }

        vector<int>ans(5,0);

        int sum = -1e9;

        ans[2] = ans[3] = ans[4] = -1;

        if(ind + k <= nums.size()){
            int temp = nums[ind+k-1] - ((ind==0)?0:nums[ind-1]);
            auto it = dp(nums,rem-1,k,ind+k);
            if(it[0] == 1){
                sum = temp + it[1];
                ans[0] = 1;
                ans[1] = sum;
                ans[3-rem+2] = ind;
                if(it[2]!=-1)ans[2] = it[2];
                if(it[3]!=-1)ans[3] = it[3];
                if(it[4]!=-1)ans[4] = it[4];
            }
        }

        auto it = dp(nums, rem, k,ind+1);

        if(it[0] == 1){
            if(it[1]>sum){
                sum = it[1];
                ans[0] = 1;
                ans[1] = sum;
                ans[2] = ans[3] = ans[4] = -1;
                // ans[3-rem+2] = ind;
                if(it[2]!=-1)ans[2] = it[2];
                if(it[3]!=-1)ans[3] = it[3];
                if(it[4]!=-1)ans[4] = it[4];
            }
        }

        if(ans[0] == 0){
            return {0,0,-1,-1,-1};
        }

        mp[{rem,ind}] = ans;

        return ans;
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        for(int i = 1;i<nums.size();i++){
            nums[i] += nums[i-1];
        }

        auto it = dp(nums,3,k,0);

        
        vector<int>ans = {it[2],it[3],it[4]};

        return ans;
        
    }
};