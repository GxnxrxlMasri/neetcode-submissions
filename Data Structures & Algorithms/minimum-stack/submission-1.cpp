#include <climits>

class MinStack {
   public:
    stack<int> st;
    stack<int> minStack;
    int size;
    MinStack() {
        size = 0;
    }

    void push(int val) {
        st.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }else{
            minStack.push(min(minStack.top(),val));
        }
        size++;
    }

    void pop() {
        st.pop();
        minStack.pop();
        size--;
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minStack.top();
    }
};
