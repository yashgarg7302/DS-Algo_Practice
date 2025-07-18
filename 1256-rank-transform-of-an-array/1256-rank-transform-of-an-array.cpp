class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         vector<int> ans(arr.size());
        unordered_map<int, pair<int, int>> mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

        for (int i = 0; i < arr.size(); i++) {
            minh.push({arr[i], i});
        }

        int rank = 1;
        while (!minh.empty()) {
            int value = minh.top().first;
            int index = minh.top().second;

            if (mpp.find(value) == mpp.end()) {
                mpp[value] = {rank++, index};
            }

            ans[index] = mpp[value].first;
            minh.pop();
        }

        return ans;
    }
};