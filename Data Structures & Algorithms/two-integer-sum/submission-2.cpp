class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> st;
        int size= nums.size();
        for(int i=0;i<size;i++)
        {
            int diff = target-nums[i];
            if(st[diff])
            {
                return { st[diff]-1,i};
            }
            st[nums[i]] = i+1;
            
        }
        return {-1,-1};
        
    }
};
