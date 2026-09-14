class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL = 0;
        int maxR = 0;

        int l = 0;
        int r = n - 1;
        int output = 0;
        while (l < r) {
            maxL = std::max(maxL, height[l]);
            maxR = std::max(maxR, height[r]);

            if (height[l] <= height[r]) {
                l++;
                output += std::max(0, std::min(maxL, maxR) - height[l]);
            } else {
                r--;
                output += std::max(0, std::min(maxL, maxR) - height[r]);
            }
        }
        return output;
    }
};
