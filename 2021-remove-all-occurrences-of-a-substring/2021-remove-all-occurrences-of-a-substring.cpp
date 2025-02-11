class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (true) {
        size_t pos = s.find(part);
        if (pos == string::npos) {
            break;
        }
        s.erase(pos, part.length());
    }
    return s;
        
    }
};