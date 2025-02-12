class Solution {
public:
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maximumSum(vector<int>& nums) {
    unordered_map<int, vector<int>> digitSumMap; 
    int maxSum = -1;
    for (int num : nums) {
        int sum = sumOfDigits(num);
        digitSumMap[sum].push_back(num);
    }
    for (auto& group : digitSumMap) {
        vector<int>& numbers = group.second;
        if (numbers.size() >= 2) {
            sort(numbers.rbegin(), numbers.rend());
            int currentSum = numbers[0] + numbers[1];
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
    }
};