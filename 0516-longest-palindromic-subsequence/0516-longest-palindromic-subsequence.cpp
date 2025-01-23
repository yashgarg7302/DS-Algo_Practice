class Solution {
public:
     // Logic : LPS(a) = LCS(a,reverse(a))

     int lcs(string x, string y, int n){
        int dp[n+1][n+1];

        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        for(int j=1; j<=n; j++)
            dp[0][j] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(x[i-1]==y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string y = s;
        reverse(y.begin(),y.end());
        int n = s.size();
        return lcs(s,y,n);
        
    }
};