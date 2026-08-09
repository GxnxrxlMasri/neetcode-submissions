class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size()+1);
        for(int i : nums){
            count[i]++;
        }

        for(const auto& element : count){
            freq[element.second].push_back(element.first);
        }

        vector<int> result;
        for(int i = freq.size()-1; i>0; i--){

            for(int j=0;j<freq[i].size(); j++){
                result.push_back(freq[i][j]);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};