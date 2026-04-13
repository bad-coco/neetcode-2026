class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int diff = target - nums[i];
             
            if(mp[diff]-1>=0) return {mp[diff]-1,i};
            else {
                mp[nums[i]] = i+1;
            }
            
        }
        return {0,0};

    }
};
