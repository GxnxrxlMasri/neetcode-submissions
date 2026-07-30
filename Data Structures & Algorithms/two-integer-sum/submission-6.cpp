class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       std::unordered_map<int, int> hashSet;
       for(int i=0;i<nums.size();i++){
        hashSet[nums[i]] = i;
       }
       int diff;
       for(int i=0; nums.size();i++){
        if(hashSet.contains((target - nums[i])) && (i != hashSet[target-nums[i]])){
            return {i, hashSet[target-nums[i]]};
        }

       }
    }
};
