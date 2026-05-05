class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> leftSum(size);
        vector<int> rightSum(size);

        for (int i = size - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }
        if(rightSum[0]==0) return 0;
        int sum = 0;
        for (int i = 1; i < size; i++) {
            sum = sum + nums[i-1];
           if(rightSum[i]==sum)
           {
            return i;
           }
        }
        return -1;
    }
};

// [1,7,3,6,5,6]
// [27,20, 17,11, 6, 0]
// [0, 1,  8, 11,17,22]