class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        int i = 0, j = 0;

        while (i <= j && j < nums.size()) {
           
            if (sum == k) {
                count++;
                j++;
            } else if (sum < k) {
                 sum += nums[j];
                j++;
            } else {
                sum -= nums[i++];
            }
        }
        if (sum == k) {
            count++;
        }
        return count;
    }
};

// [2,-1,1,2] , k =2

// sum  = 0 +2 = 2

// [2,1,1,2]
//