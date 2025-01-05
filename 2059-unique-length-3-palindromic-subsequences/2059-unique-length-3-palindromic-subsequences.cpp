class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,vector<int>>ok;
        int ans=0;
        for(int i=0;i<s.size();i++)ok[s[i]].push_back(i);

        for(auto x: ok)
        {
            vector<int>temp=x.second;
           
            int l=temp.front(); int r=temp.back();
            vector<bool> check(26,false);
           
            
            if(temp.size()>1)
            for(int i=l+1;i<r;i++)
            {   
                if(!check[s[i]-'a'])
                {ans++;}
                check[s[i]-'a']=true;
            }
        }

        return ans;
    }
};