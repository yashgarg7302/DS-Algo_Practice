class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
       
        int n = nums.size();
        unordered_map<int, int> productCount;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        } 
        int result = 0;
        for(auto& pair : productCount) {
            int count = pair.second;
            if(count > 1) {
                result += count * (count - 1) / 2 * 8;
            }
        }
        return result;
    }
};