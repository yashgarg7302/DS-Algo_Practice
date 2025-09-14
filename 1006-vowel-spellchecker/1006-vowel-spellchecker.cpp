class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
         unordered_set<string> exactWords;              
        unordered_map<string, string> caseInsensitive;   
        unordered_map<string, string> vowelMasked;       
        
        auto toLower = [](const string& word) -> string {
            string lower;
            lower.reserve(word.size());
            for (char c : word) 
                lower.push_back(tolower(c));
            return lower;
        };
        
        auto maskVowels = [](const string& word) -> string {
            string masked;
            masked.reserve(word.size());
            for (char c : word) {
                char lc = tolower(c);
                if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
                    masked.push_back('*');
                else
                    masked.push_back(lc);
            }
            return masked;
        };
        
        for (const string& word : wordlist) {
            exactWords.insert(word);
            
            string lowerWord = toLower(word);
            if (caseInsensitive.find(lowerWord) == caseInsensitive.end()) {
                caseInsensitive[lowerWord] = word;
            }
            
            string maskWord = maskVowels(word);
            if (vowelMasked.find(maskWord) == vowelMasked.end()) {
                vowelMasked[maskWord] = word;
            }
        }
        
        vector<string> result;
        result.reserve(queries.size());
        
        for (const string& query : queries) {
            if (exactWords.count(query)) {
                result.push_back(query);
                continue;
            }
            string lowerQuery = toLower(query);
            auto itCase = caseInsensitive.find(lowerQuery);
            if (itCase != caseInsensitive.end()) {
                result.push_back(itCase->second);
                continue;
            }
            string maskQuery = maskVowels(query);
            auto itVowel = vowelMasked.find(maskQuery);
            if (itVowel != vowelMasked.end()) {
                result.push_back(itVowel->second);
                continue;
            }
            
            result.push_back("");
        }
        
        return result;
    }
};