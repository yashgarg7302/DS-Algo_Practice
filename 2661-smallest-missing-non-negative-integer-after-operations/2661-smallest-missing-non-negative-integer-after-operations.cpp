class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> cnt;
    for (long long x : nums) {
        int r = ((x % value) + value) % value;
        cnt[r]++;
    }
    int mex = 0;
    while (true) {
        int r = mex % value;
        if (cnt[r] > 0) {
            cnt[r]--;
            mex++;
        } else break;
    }
    return mex; 
    }
};