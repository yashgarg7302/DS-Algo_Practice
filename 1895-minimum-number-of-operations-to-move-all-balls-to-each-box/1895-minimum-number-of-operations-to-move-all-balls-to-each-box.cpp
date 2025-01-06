class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> ans(len, 0);
        vector<int> res;

        for(int i=0; i<len; i++){
            if(boxes[i] == '1') {
                res.push_back(i+1);
            }
        }

        for(int i=0; i<len; i++){
            int count = 0;
            for(int j=0; j<res.size(); j++){
                count += abs(i+1-res[j]);
            }
            ans[i] = count;
        }
        return ans;
    }
};