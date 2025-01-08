class Solution {
public:

    bool isPrefixAndSuffix(string s1, string s2){

        int n = s2.size(), m = s1.size() ;
        if(n < m) return false ;

        for(int i=0; i<m; i++){
            if(s1[i] != s2[i]) return false ;
            if(s2[n - m + i] != s1[i]) return false ;
        }

        return true ;


    }

    int countPrefixSuffixPairs(vector<string>& words) {

        int n = words.size() ;
        int ans = 0 ;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans += isPrefixAndSuffix(words[i], words[j]) ;
            }
        }

        return ans ;
        
    }
};