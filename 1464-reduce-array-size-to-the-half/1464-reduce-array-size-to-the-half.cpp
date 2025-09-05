class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    
    vector<int> counts;
    for (auto &p : freq) {
        counts.push_back(p.second);
    }
    
    sort(counts.rbegin(), counts.rend()); 
    
    int removed = 0, setSize = 0, half = arr.size() / 2;
    for (int c : counts) {
        removed += c;
        setSize++;
        if (removed >= half) break;
    }
    
    return setSize;
    }
};