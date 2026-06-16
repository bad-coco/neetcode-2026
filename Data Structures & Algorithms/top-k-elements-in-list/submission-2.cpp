using pint = pair<int, int>;
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> result;
        for (int val : nums) {
            freq[val]++;
        }
        priority_queue<pint, vector<pint>, greater<pint>> minHeap;
        for (auto item : freq) {
            minHeap.push({item.second, item.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        while (minHeap.size()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

// [1,2,2,3,3,3]
// 1=1, 2=2,3=3