class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productTotal = 1;
        int zeroCount = 0;
        for (int num : nums) {
            if (num == 0)
                zeroCount++;
            else
                productTotal *= num;
        }
        if (zeroCount > 1) {
            vector<int> result(nums.size(), 0);
            return result;
        }
        vector<int> result;
        for (int num : nums) {
            if (zeroCount == 1) {
                if (num == 0) {
                    result.push_back(productTotal);
                } else {
                    result.push_back(0);
                }
            } else {
                int temp = (int)(productTotal / num);
                result.push_back(temp);
            }
        }
        return result;
    }
};

 