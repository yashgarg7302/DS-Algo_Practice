class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            for(int j=0;j<n;j++){
                    if(strs[j][i] != ch || i>=strs[j].length()){
                         return ans;
                    }
            }    
                  ans = ans + ch; 
    }
    return ans;
    }
};