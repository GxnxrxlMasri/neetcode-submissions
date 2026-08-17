class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [1, 2, 4, 6]     nums
        // [1, 1, 2, 8]     prefix
        // [48, 24, 6, 1]   suffix
        // [48, 24, 12, 8]  product

        int s = nums.size();
        vector<int> prefix(s, 1);
        int preProduct = 1;

        vector<int> suffix(s, 1);
        int sufProduct = 1;

        for (int i = 1; i < s; i++) {
            preProduct *= nums[i - 1];
            prefix[i] = preProduct;

            sufProduct *= nums[s - i];
            suffix[s - i - 1] = sufProduct;
        }

        // for (int i = nums.size() - 2; i > -1; i--) {
        //     sufProduct *= nums[i + 1];
        //     suffix[i] = sufProduct;
        // }
        vector<int> result(s);
        for (int i = 0; i < s; i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
