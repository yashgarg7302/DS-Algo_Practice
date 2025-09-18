class Solution {
public:
    int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return 0;
    }

    int min_val = nums[0];
    int max_val = nums[0];
    for (int num : nums) {
        min_val = min(min_val, num);
        max_val = max(max_val, num);
    }
    
    if (min_val == max_val) {
        return 0;
    }
    int bucket_size = max(1, (max_val - min_val) / (n - 1));
    int bucket_count = (max_val - min_val) / bucket_size + 1;

    vector<pair<int, int>> buckets(bucket_count, {INT_MAX, INT_MIN});
    
    for (int num : nums) {
        int bucket_index = (num - min_val) / bucket_size;
        buckets[bucket_index].first = min(buckets[bucket_index].first, num);
        buckets[bucket_index].second = max(buckets[bucket_index].second, num);
    }
    int max_gap = 0;
    int prev_max = min_val;
    for (const auto& bucket : buckets) {
        if (bucket.first == INT_MAX) {
            continue;
        }
        max_gap = max(max_gap, bucket.first - prev_max);
        prev_max = bucket.second;
    }
    return max_gap;
    }
};