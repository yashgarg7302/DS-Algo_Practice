class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string toLower(const string& word) {
        string res = word;
        for (char &c : res) c = tolower(c);
        return res;
    }

    string devowel(const string& word) {
        string res = word;
        for (char &c : res) {
            if (isVowel(c)) c = '*';
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords;
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelError;

        for (const string& word : wordlist) {
            exactWords.insert(word);

            string lowerWord = toLower(word);
            if (caseInsensitive.find(lowerWord) == caseInsensitive.end()) {
                caseInsensitive[lowerWord] = word;
            }

            string devowelWord = devowel(lowerWord);
            if (vowelError.find(devowelWord) == vowelError.end()) {
                vowelError[devowelWord] = word;
            }
        }

        vector<string> result;
        for (const string& query : queries) {
            if (exactWords.find(query) != exactWords.end()) {
                result.push_back(query);
                continue;
            }

            string lowerQuery = toLower(query);
            if (caseInsensitive.find(lowerQuery) != caseInsensitive.end()) {
                result.push_back(caseInsensitive[lowerQuery]);
                continue;
            }

            string devowelQuery = devowel(lowerQuery);
            if (vowelError.find(devowelQuery) != vowelError.end()) {
                result.push_back(vowelError[devowelQuery]);
                continue;
            }

            result.push_back("");
        }

        return result;
    
    }
};