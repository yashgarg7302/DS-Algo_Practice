class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int total = 0;
        for(int &a: derived)
            total = total ^ a;
        return total == 0;
    }
};