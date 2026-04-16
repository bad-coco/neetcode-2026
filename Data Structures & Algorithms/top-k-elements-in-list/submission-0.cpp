typedef pair<int, int> pint;
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        priority_queue<pint, vector<pint>, greater<pint>> minHeap;
        vector<int> result;
        for (int num : nums) {
            frequencyMap[num]++;
        }
        for (const auto& freqPair : frequencyMap) {
            minHeap.push({freqPair.second, freqPair.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
