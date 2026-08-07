class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            if (count.contains(nums[i])) {
                count[nums[i]]++;
            } else {
                count.insert({nums[i], 1});
            }
        }

        vector<int> max;

        int maxValue;
        int maxKey;
        for (int i = 0; i < k; i++) {
            maxValue = std::numeric_limits<int>::min();
            for (const auto& [key, value] : count) {
                if (value > maxValue) {
                    maxValue = value;
                    maxKey = key;
                }
            }
            max.push_back(maxKey);
            count.erase(maxKey);
        }
        return max;
    }
};
