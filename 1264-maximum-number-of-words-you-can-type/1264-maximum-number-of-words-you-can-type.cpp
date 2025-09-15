class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> v(26,0);
        int broken=0,count=0;
        for(int i=0;i<brokenLetters.length();i++)
        {
            v[brokenLetters[i]-'a']=1;
        }
        for(int i=0;i<text.length();i++)
        {
            if(text[i]==' ')
            {
                if(broken==0)
                count++;
                broken=0;
            }
            else if(v[text[i]-'a']==1)
            {
                broken++;
            }
        }
        if(broken==0)
            count++;
    return count;

    }
};