class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        // Solution without extra space
        int total = 0;
        int leftSum = 0;
        int n = nums.size();
        for (int num : nums) {
            total += num;
        }

        for (int i = 0; i < n; i++) {
            int rightSum = total - leftSum - nums[i];
            if (rightSum == leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};

// [10,30,20,40] = 100
//
// left = 0
// right = 100 - 0 -10

// left = 10
// right = 100- 10(left) - 30(arr[i]) = 60

//  left = 40
// right = 100 - 40 - 20 = 40