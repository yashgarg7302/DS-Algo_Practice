class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long , vector<long long >, greater<long long>> q(nums.begin(),nums.end());
        int operations = 0;
        while (q.top() < k) {
            long long  first = q.top();
            q.pop();
            long long second = q.top();
            q.pop();


            q.push(first * 2 + second);
            operations++;
        }
        return operations;
    }
};