class Solution {
   private:
    string generateWord(string& word) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        string new_word = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                new_word += string(freq[i], i + 'a');
            }
        }
        return new_word;
    }

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for (string word : strs) {
            string new_word = generateWord(word);
            mp[new_word].push_back(word);
        }
        for (auto item : mp) {
            result.push_back(item.second);
        }
        return result;
    }
};
