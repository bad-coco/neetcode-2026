class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramFreq;
        vector<vector<string>> result;

        for (string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            anagramFreq[temp].push_back(str);
        }
        for (auto& item : anagramFreq) {
            result.push_back(item.second);
        }
        return result;
    }
};
