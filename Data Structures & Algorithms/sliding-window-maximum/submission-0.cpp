class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < k; i++) {
            heap.push({nums[i], i});
        }

        vector<int> maxOutput;
        maxOutput.push_back(heap.top().first);
        int l = 0;
        for (int r = k; r < nums.size(); r++) {
            heap.push({nums[r],r});
            l++;
            while (heap.top().second < l) {
                heap.pop();
            }
            maxOutput.push_back(heap.top().first);
        }
        return maxOutput;
    }
};
