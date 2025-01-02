class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> v1(n, 0);
        vector<int> v2;
        for(int i = 0; i < n; i++) {
            string s = words[i];
            if(isVowel(s[0]) && isVowel(s[s.size() - 1])) {
                if(i > 0)
                    v1[i] = v1[i - 1] + 1;
                else
                    v1[i] = 1;
            }
            else {
                if(i > 0)
                    v1[i] = v1[i - 1];
            }
        }
        for(auto &i: queries) {
            if(i[0] > 0)
                v2.push_back(v1[i[1]] - v1[i[0] - 1]);
            else
                v2.push_back(v1[i[1]]);
        }
        return v2;
    }
};