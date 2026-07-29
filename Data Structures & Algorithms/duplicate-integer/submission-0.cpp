class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniqueNums;
        for(int i=0; i< nums.size();i++){
            if(uniqueNums.contains(nums[i])){
                return true;
            }else{
                uniqueNums.insert(nums[i]);
            }
        }
        return false;
    }
};