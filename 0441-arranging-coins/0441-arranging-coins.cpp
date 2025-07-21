class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1) return 1;
        int i=1;
        int ans=0;
        
        while(n >= i){
            n = n-i;
            i++;
            ans++;
        }
        return ans;
    }
};