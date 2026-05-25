class Solution {
    string generateWord(string str) {
        vector<int> freq(26, 0);

        for (char ch : str) {
            freq[ch - 'a']++;
        }
        string newWord = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                newWord += string(freq[i], i + 'a');
            }
        }
        return newWord;
    }

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        // iterate through the array
        for (string str : strs) {
            // sort the string => act : ['act','cat']
            mp[generateWord(str)].push_back(str);
        }
        for (auto item : mp) {
            result.push_back(item.second);
        }
        // iterate through the map and return the key
        return result;
    }
};
