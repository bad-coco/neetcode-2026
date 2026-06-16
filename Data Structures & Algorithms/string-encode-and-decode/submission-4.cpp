class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (string str : strs) {
            encoded_string += to_string(str.size()) + "#" + str;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);

            decoded_string.push_back(word);
            
            i = j + len + 1;
        }

        return decoded_string;
    }
};
// "Hello","World"
// "5#Hello23#World"