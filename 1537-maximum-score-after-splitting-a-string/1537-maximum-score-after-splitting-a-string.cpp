class Solution {
public:
    int maxScore(string s) {
        int ans =0;
        int n = s.size();
       int l =0;
       for( int i=0;i<n-1;i++)
        {
         if (s[i]=='0') {
           l++;
         }
       int r =0;
       for (int j=i+1;j<n;j++){
         if (s[j]=='1'){
            r++;
         }
       } 
       ans = max(ans,l+r);
       }
       return ans; 
    }
};