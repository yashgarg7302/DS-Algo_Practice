class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> node, color;

        for (auto& q : queries) {
            int x = q[0], y = q[1];

            if (node.count(x)) {
                int prevColor = node[x];
                if (prevColor == y) {
                    ans.push_back(color.size());
                    continue;
                }
                if (--color[prevColor] == 0) color.erase(prevColor);
            }

            node[x] = y;
            color[y]++;
            ans.push_back(color.size());
        }

        return ans;
    }
};