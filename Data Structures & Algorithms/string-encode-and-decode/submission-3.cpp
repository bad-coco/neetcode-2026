class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // find '#'
            while (s[j] != '#') j++;

            // correct length extraction
            int len = stoi(s.substr(i, j - i));

            // extract string
            string word = s.substr(j + 1, len);
            decoded.push_back(word);

            // move pointer
            i = j + 1 + len;
        }

        return decoded;
    }
};