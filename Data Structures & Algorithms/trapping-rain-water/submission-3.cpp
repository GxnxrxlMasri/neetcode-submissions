class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        int currentMax = height[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = std::max(currentMax, maxLeft[i - 1]);
            currentMax = std::max(currentMax, height[i]);
        }
        currentMax = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = std::max(currentMax, maxRight[i + 1]);
            currentMax = std::max(currentMax, height[i]);
        }

        // for (int i = 0; i < n; i++) {
        //     cout << maxLeft[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << maxRight[i] << " ";
        // }
        // cout << endl;
        int output = 0;
        for (int i = 1; i < n - 1; i++) {
            output += std::max(0, std::min(maxLeft[i], maxRight[i]) - height[i]);
        }
        return output;
    }
};
