class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashSet;
        for (int i = 0; i < nums.size(); i++) {
            if (hashSet.contains(target - nums[i])) {
                return {hashSet[target - nums[i]], i};
            }
            hashSet[nums[i]] = i;
        }
    }
};
