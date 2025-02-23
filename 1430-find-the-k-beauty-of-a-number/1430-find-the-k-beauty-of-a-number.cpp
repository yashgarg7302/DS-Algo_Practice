class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string num1 = to_string(num);
        int n = num1.length();
        if (k > n) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i <= n - k; i++) {
            string substring = num1.substr(i, k);
            int subNum = stoi(substring);
            if (subNum != 0 && num % subNum == 0) {
                count++;
            }
        }
        return count;
    }
};