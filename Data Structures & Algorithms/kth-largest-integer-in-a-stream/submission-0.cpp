class KthLargest {
private: 
    priority_queue<int, vector<int>,greater<int>> minH;
    int k; 
public:
    KthLargest(int k, vector<int>& nums) {
        int size = nums.size();
        this->k = k;
        for(int i=0;i<size;i++)
        {
            this->add(nums[i]);
        }
        
    }
    
    int add(int val) {
        minH.push(val);
        if(minH.size()>k)
        {
            minH.pop();
        }
        return minH.top(); 
    }
};
