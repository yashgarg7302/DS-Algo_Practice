class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n=words.size();
        string str="";
        for(int i=0; i<n; i++){
            str= str + words[i];
            if( s == str ){
                return true;
            }
        }
        return false;
    }
};