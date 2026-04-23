class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> result;

        for (auto point : points) {
            int x = point[0];
            int y = point[1];
            int distance =  abs(x) + abs(y);

            maxHeap.push({distance, point});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            vector<int> point = maxHeap.top().second;
            maxHeap.pop();
            result.push_back(point);
        }
        return result;
    }
};
