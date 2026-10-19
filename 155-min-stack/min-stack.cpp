class MinStack {
private:
    stack<long> st;
    long mini;
public:
    MinStack() {
        mini = LONG_MAX;
    }
    
    void push(int value) {
        if(st.empty()) {
            mini = value;
            st.push(value);
        }
        else {
            if(value >= mini) st.push(value);
            else {
                st.push(2 * (long)value - mini);
                mini = value;
            } 
        }
    }
    
    void pop() {
        long x = st.top();
        if(x >= mini) st.pop();
        else {
            mini = 2 * mini - x;
            st.pop();
        }
    }
    
    int top() {
        long x = st.top();
        if(x >= mini) return x;
        else return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */