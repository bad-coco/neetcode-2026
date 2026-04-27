class Solution {
   private:
    char separator = char(257);

   public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string str : strs) {
            encoded += str + separator;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string temp = "";
        for (char ch : s) {
            if (ch != separator) {
                temp += ch;
            } else {
                result.push_back(temp);
                temp = "";
            }
        }
        return result;
    }
};
