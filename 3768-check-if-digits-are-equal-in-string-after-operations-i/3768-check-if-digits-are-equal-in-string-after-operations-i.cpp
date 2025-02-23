class Solution {
public:
    bool hasSameDigits(string s) {
        if (s.length() == 2) {
        return s[0] == s[1];
    }
    string s1 = "";
    for (int i = 0; i < s.length() - 1; i++) {
        int digit1 = s[i] - '0';  
        int digit2 = s[i + 1] - '0';
        int sum = (digit1 + digit2) % 10;
        s1 += to_string(sum);   
    }
    return hasSameDigits(s1);
    }
};