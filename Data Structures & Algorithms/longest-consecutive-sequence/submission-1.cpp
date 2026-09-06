class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique;

        for(int n: nums){
            if(!unique.contains(n)){
                unique.insert(n);
            }
        }
        vector<int> starts;
        for(int n: unique){
            if(!unique.contains(n-1)){
                starts.push_back(n);
            }
        }
        int max = 0;
        for(int n:starts){
            int count = 1;
            while(unique.contains(n+1)){
                count++;
                n++;
            }
            if(count > max){
                max = count;
            }
        }
        return max;
    }
};
