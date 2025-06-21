class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
    for (char c : word) freq[c - 'a']++;
    vector<int> counts;
    for (int f : freq) if (f > 0) counts.push_back(f);

    sort(counts.begin(), counts.end());
    int n = counts.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int min_freq = counts[i];
        int max_freq = min_freq + k;
        int deletions = 0;

        for (int f : counts) {
            if (f < min_freq) deletions += f; 
            else if (f > max_freq) deletions += (f - max_freq);
        }
        ans = min(ans, deletions);
    }
    return ans;
    }
};