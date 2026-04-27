class Solution {
    char separator = '#';

   public:
    string encode(vector<string>& strs) {
        string encoded_str = "";
        for (string str : strs) {
            encoded_str += to_string(str.size()) + separator + str;
        }
        cout << encoded_str << endl;
        return encoded_str;
    }

    vector<string> decode(string str) {
        vector<string> result;
        int size = str.size();

        int i = 0, j = 0;
        while (i < size) {
            j = i;
            while (str[j] != separator) {
                j++;
            }
            int len = stoi(str.substr(i, j - i));
            string temp = str.substr(j+1, len);
            result.push_back(temp);
            i = j + len + 1;
        }
        return result;
    }
};
