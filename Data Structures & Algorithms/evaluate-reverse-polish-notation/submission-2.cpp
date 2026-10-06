class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int output = 0;
        int n1;
        int n2;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                n1 = std::stoi(st.top());
                st.pop();
                n2 = std::stoi(st.top());
                st.pop();
                output = (n1 + n2);
                st.push(to_string(output));
            } else if (tokens[i] == "-") {
                n1 = std::stoi(st.top());
                st.pop();
                n2 = std::stoi(st.top());
                st.pop();
                output = (n2 - n1);
                st.push(to_string(output));
            } else if (tokens[i] == "*") {
                n1 = std::stoi(st.top());
                st.pop();
                n2 = std::stoi(st.top());
                st.pop();
                output = (n2 * n1);
                st.push(to_string(output));
            } else if (tokens[i] == "/") {
                n1 = std::stoi(st.top());
                st.pop();
                n2 = std::stoi(st.top());
                st.pop();
                output = (n2 / n1);
                st.push(to_string(output));
            } else {
                st.push(tokens[i]);
            }
        }
        return std::stoi(st.top());
    }
};
