class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
         int i = 0;     
        int wordIndex = 1; 
        while (i < sentence.size()) {
            int start = i;
            while (i < sentence.size() && sentence[i] != ' ') {
                i++;
            }
            string currentWord = sentence.substr(start, i - start);
            if (currentWord.find(searchWord) == 0) {
                return wordIndex;
            }
            while (i < sentence.size() && sentence[i] == ' ') {
                i++;
            }
            wordIndex++;
        }
        return -1;
    }
};