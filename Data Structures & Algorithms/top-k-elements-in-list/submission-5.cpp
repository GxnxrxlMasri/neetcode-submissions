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

        vector<vector<int>> freq(nums.size()+1);
        int key;
        int value;
        for (auto it = count.begin(); it!= count.end(); ++it){
            key = it->first;
            value= it->second;
            freq[value].push_back(key);
        }

        vector<int> result;
        vector<int> tempArr;
        for(int i = freq.size()-1; i>0;i--){
            tempArr = freq[i];
            for(int j =0; j<tempArr.size();j++){
                result.push_back(tempArr[j]);
                if(result.size() == k){
                    return result;
                }
            }
        }
       return {};
    }
};
