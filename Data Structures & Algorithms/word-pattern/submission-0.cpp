class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToWord;
        unordered_map<string, int> wordToChar;
        istringstream in(s);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || charToWord[pattern[i]] != wordToChar[word]) {
                return false;
            }
            charToWord[pattern[i]] = wordToChar[word] = i + 1;
        }
        return i == n;
    }
};