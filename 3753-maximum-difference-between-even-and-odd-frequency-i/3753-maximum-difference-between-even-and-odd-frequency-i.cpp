class Solution {
public:
    int maxDifference(string s) {
        std::unordered_map<char, int> frequencyMap;
        for (char c : s) {
            frequencyMap[c]++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        
        std::vector<int> frequencies;
        for (const auto& pair : frequencyMap) {
            frequencies.push_back(pair.second);
        }

       
        for (int freq : frequencies) {
            if (freq % 2 == 0) {
                if (freq < minEven) {
                    minEven = freq;
                }
            } else {
                if (freq > maxOdd) {
                    maxOdd = freq;
                }
            }
        }

        if (maxOdd == INT_MIN || minEven == INT_MAX) {
            return 0; 
        }
        return maxOdd - minEven;
    }
};