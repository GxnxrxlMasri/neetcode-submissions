class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int output = 0;
        int n1;
        int n2;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                output = (n1 + n2);
                st.push(output);
            } else if (tokens[i] == "-") {
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                output = (n2 - n1);
                st.push(output);
            } else if (tokens[i] == "*") {
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                output = (n2 * n1);
                st.push(output);
            } else if (tokens[i] == "/") {
                n1 = st.top();
                st.pop();
                n2 = (st.top());
                st.pop();
                output = (n2 / n1);
                st.push(output);
            } else {
                st.push(std::stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
