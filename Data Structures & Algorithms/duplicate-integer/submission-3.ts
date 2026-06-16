class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums: number[]): boolean {
        const mp = new Map();

        for (let i = 0; i < nums.length; i++) {
            let currentCount = mp.get(nums[i]) || 0;
            currentCount++;
            mp.set(nums[i], currentCount);
            if (currentCount > 1) {
                return true;
            }
        }
        return false;
    }
}
