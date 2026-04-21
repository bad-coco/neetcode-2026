class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);
        priority_queue<int> maxHeap;

        for (char ch : tasks) {
            frequency[ch - 'A']++;
        }
        for (int freq : frequency) {
            if (freq > 0) {
                maxHeap.push(freq);
            }
        }
        int interval = 0;
        queue<pair<int, int>> normalQue;
        while (!maxHeap.empty() || !normalQue.empty()) {
            interval++;

            if (!maxHeap.empty()) {
                if (maxHeap.top() - 1 > 0) {
                    normalQue.emplace(maxHeap.top() - 1, interval + n);
                }
                maxHeap.pop();
            }
            if (!normalQue.empty()) {
                auto [first, second] = normalQue.front();
                if (second <= interval) {
                    normalQue.pop();

                    maxHeap.emplace(first);
                }
            }
        }

        return interval;
    }
};
// ["X","X","Y","Y"], n = 2
//

// X Y _
//
// in = 3

//  (1, 3), (1, 4)

//  x = 1
// y = 1
