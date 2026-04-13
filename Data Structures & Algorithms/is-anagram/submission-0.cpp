class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
       vector<int> chara(26, 0);
        int count =0;
        for(int i=0;i<s.size();i++)
        {
            chara[s[i]-'a']++;
            if(chara[s[i]-'a']==1)
            {
                count++;
            }
        }
           for(int i=0;i<t.size();i++)
        {
            chara[t[i]-'a']--;
            if(chara[t[i]-'a']==0)
            {
                count--;
            }
        }
        if(count==0)
        {
            return true;
            
        }
        return false;
 
    }
};
