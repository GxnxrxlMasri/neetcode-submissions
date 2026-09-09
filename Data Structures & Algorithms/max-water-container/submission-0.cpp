class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() -1;

        int max = 0;
        while (l < r){
            int area = std::min(heights[l],heights[r]) * (r-l);
            max = std::max(area, max);

            if(heights[l] > heights[r]){
                r--;
            }else{
                l++;
            }
        }
        return max;
    }
};
