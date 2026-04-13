class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        vector<int> frequency(26);
        for(char character: s)
        {
            frequency[character-'a']++;

        }
        for(char character: t)
        {
             if(--frequency[character-'a']<0)
             {
                return false;

             }
        }
       
        return true;
    
 
    }
};
