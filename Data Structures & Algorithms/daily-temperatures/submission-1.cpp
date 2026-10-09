class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        vector<int> output(temp.size());
        for (int i = 0; i < temp.size(); i++) {
            while (!st.empty() && temp[i] > st.top().first) {
                output[st.top().second] = (i - st.top().second);
                st.pop();
            }
            st.push({temp[i], i});
        }
        return output;
    }
};
