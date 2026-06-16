class Solution {
    string generateWord(string str) {
        string newWord="";
        vector<int> wordCount(26,0);
        for(char c:str){
            wordCount[c-'a']++;
        }
        for(int i=0;i<wordCount.size();i++){
            if(wordCount[i]>0){
                
                newWord+=string(wordCount[i],i+'a');
            }
        }
        return newWord;
    }

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        vector<vector<string>> result;
        for(string str : strs){
            string newWord = generateWord(str);
            freq[newWord].push_back(str);
        }
        for(auto item:freq){
            result.push_back(item.second);
        }
        return result;
    }
};
// ["act","pots","tops","cat","stop","hat"]
//
// Map
// "act" : ["act"]
// "opst" : ["pots"]
// "opst" : ["pots","tops"]
// "act" : ["pots","tops","cat"]