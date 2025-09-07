class Solution {
public:
    int func(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i=0;i<n;++i){
            int even = func(s,i,i+1);
            int odd = func(s,i,i);
            count += even + odd;
        }
        return count;
    }
};