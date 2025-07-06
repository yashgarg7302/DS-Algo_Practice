class Solution {
public:
   vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, "", 0, 0, result);
        return result;
    }
    void backtrack(const string &num, int target, int pos, string path, long calculated, long last_operand, vector<string> &result) {
        if (pos == num.size()) {
            if (calculated == target) {
                result.push_back(path);
            }
            return;
        }
        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break;
            string curr_str = num.substr(pos, i - pos + 1);
            long curr_num = stol(curr_str);
            if (pos == 0) {
                backtrack(num, target, i + 1, curr_str, curr_num, curr_num, result);
            } else {
                backtrack(num, target, i + 1, path + "+" + curr_str, calculated + curr_num, curr_num, result);
                backtrack(num, target, i + 1, path + "-" + curr_str, calculated - curr_num, -curr_num, result);
                backtrack(num, target, i + 1, path + "*" + curr_str, calculated - last_operand + last_operand * curr_num, last_operand * curr_num, result);
            }
        }
    }
};