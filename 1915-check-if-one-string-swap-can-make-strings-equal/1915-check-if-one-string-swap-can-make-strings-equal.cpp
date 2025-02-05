class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
        return true;
        int i = 0, j = s1.size()-1;
        while(s1[i]==s2[i])
        i++;
        while(s1[j]==s2[j])
        j--;
        swap(s2[j],s2[i]);
        return s1==s2;
    }
};