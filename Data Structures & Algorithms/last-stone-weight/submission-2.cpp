class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        
        while (maxHeap.size() > 1) {
            int firstStoneWeight = maxHeap.top();
            maxHeap.pop();

            int secondStoneWeight = maxHeap.top();
            maxHeap.pop();

             

            if (firstStoneWeight !=secondStoneWeight) {
                maxHeap.push(firstStoneWeight-secondStoneWeight);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
