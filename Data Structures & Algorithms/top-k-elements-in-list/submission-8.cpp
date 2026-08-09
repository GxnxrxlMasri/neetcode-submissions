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
        for (auto it = count.begin(); it!= count.end(); ++it){
            freq[it->second].push_back(it->first);
        }

        vector<int> result;
        for(int i = freq.size()-1; i>0;i--){
            for(int j =0; j<freq[i].size();j++){
                result.push_back(freq[i][j]);
                if(result.size() == k){
                    return result;
                }
            }
        }
       return {};
    }
};
