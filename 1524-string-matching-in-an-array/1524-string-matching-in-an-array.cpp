class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> a;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) { 
                int pos = words[j].find(words[i]);
                if (j != i && pos >= 0 && pos < words[j].length()) {
                    a.push_back(words[i]);
                    break;
                }
            }
        }
        return a;
    }
};