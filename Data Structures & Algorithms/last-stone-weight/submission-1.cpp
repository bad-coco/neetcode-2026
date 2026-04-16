class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }
        while (maxHeap.size() > 1) {
            int firstStoneWeight = maxHeap.top();
            maxHeap.pop();

            int secondStoneWeight = maxHeap.top();
            maxHeap.pop();

            int difference = abs(firstStoneWeight - secondStoneWeight);

            if (difference != 0) {
                maxHeap.push(difference);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
