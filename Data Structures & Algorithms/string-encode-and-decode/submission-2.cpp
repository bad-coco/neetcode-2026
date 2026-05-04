class Solution {
   public:
    string encode(vector<string>& strs) {
        // "Hello","World"
        // "5#Hello15#World"
        //
        string encoded = "";
        for (string str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        int j = 0;
        while (i < s.size()) {
            if (s[j] != '#') {
                j++;
            } else {
                int len = stoi(s.substr(i, j));
                string temp = s.substr(j + 1, len);
                decoded.push_back(temp);
                i = j + len + 1;
                j = i + 1;
            }
        }
        return decoded;
    }
};
