class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    unordered_set<int> seenA, seenB;
    vector<int> C(n, 0);           
    for (int i = 0; i < n; ++i) {
        seenA.insert(A[i]);
        seenB.insert(B[i]);
        int commonCount = 0;
        for (int num : seenA) {
            if (seenB.count(num)) {
                ++commonCount;
            }
        }
        C[i] = commonCount;
    }
    return C;
    }
};