class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size, 1);
        int suffix = 1;
        for (int i = 1; i < size; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = size - 2; i >= 0; i--) {
            suffix = suffix * nums[i + 1];
            prefix[i] *= suffix;
        }
        return prefix;
    }
};
// [1,2,4,6]
//
//  [1, 1, 2,6] = prefix
//  [48,24,6,1] = sufix
//  [48,24,12,6]
