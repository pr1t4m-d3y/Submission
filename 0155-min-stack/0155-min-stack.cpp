class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() {}

    void push(int value) {
        if (s.empty()) {
            s.push(value);
            mini = value;
        } else if (value < mini) {
            s.push(2LL * value - mini);
            mini = value;
        } else s.push(value);
    }

    void pop() {
        long long curr = s.top();
        s.pop();
        if (curr < mini) mini = 2LL * mini - curr;
    }

    int top() {
        if (s.empty()) return -1;
        return s.top() < mini ? mini : (int)s.top();
    }

    int getMin() {
        return s.empty() ? -1 : (int)mini;
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