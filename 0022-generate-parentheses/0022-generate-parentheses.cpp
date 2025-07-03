class Solution {
public:
    void solve(int open,int close,string &op,vector<string> &v){
        if(open==0 && close==0){
            v.push_back(op);
            return ;
        }
        if(open!=0){
           op.push_back('(');
           solve(open-1,close,op,v);
           op.pop_back();
        }
        if(close>open){
           op.push_back(')');
           solve(open,close-1,op,v);
           op.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int close = n;
        int open = n;
        string op = "";
        solve(open,close,op,v);
        return v;
        }
};