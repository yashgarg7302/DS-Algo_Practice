class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         if (nums.size() == 1) {
            if(nums[0]==0 && target==0)
               return 2;
            if (abs(nums[0]) == abs(target))
                return 1;
            else
                return 0;
        }
        int z = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                z++;
        int asum = accumulate(nums.begin(), nums.end(), 0);
        if ((asum + target) % 2 == 1)
            return 0;
        int t = (asum + target) / 2;
        if (t < 0)
            return 0;
        int dp[nums.size() + 1][t + 1];
        for (int i = 0; i <= nums.size(); i++) {
            for (int j = 0; j <= t; j++) {
                dp[i][j] = 0;
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= t; j++) {
                if (nums[i - 1] == 0)
                    dp[i][j] = dp[i - 1][j];
                else if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                  dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            }
        }
        return pow(2, z) * dp[nums.size()][t];
    }
};