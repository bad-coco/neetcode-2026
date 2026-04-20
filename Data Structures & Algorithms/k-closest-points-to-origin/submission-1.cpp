class Solution {
   public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Store: {squared_distance, original_vector}
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> result;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            
            // Use squared distance to avoid floating point issues and save performance
            int squaredDistance = (x * x) + (y * y);
            
            maxHeap.push({squaredDistance, point});
            
            // If heap exceeds k, remove the largest distance
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Transfer from heap to result vector
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};
