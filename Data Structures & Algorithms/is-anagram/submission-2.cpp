class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        vector<int> anagramStorage(26);
        for(char character: s)
        {
            anagramStorage[character-'a']++;

        }
        for(char character: t)
        {
             anagramStorage[character-'a']--;
        }
        for(int value:  anagramStorage)
        {
            if(value!=0)
            {
                return false;
            }
        }
        return true;
    
 
    }
};
