class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<int, char>> pairs;
        for (auto [ch, count] : freq) {
            pairs.push_back({count, ch});
        }
        sort(pairs.rbegin(), pairs.rend());
        string result;
        for (auto [count, ch] : pairs) {
            result.append(count, ch);
        }
        return result;
    }    
    };