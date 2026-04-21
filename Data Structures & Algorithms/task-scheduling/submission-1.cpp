class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);
        priority_queue<int> maxHeap;

        for (char t : tasks) {
            frequency[t - 'A']++;
        }
        for (int freq : frequency) {
            if (freq > 0) maxHeap.push(freq);
        }
        int time = 0;
        queue<pair<int, int>> cooldown;
        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--;  // executed
                if (cnt > 0) {
                    cooldown.emplace(cnt, time + n);
                }
            }
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.emplace(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
