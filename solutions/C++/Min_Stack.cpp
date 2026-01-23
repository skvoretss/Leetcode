class MinStack {
    vector<pair<int, int>> vec;
public:
    MinStack() {}
    
    void push(int val) {
        if (vec.size() == 0)
            vec.push_back({val, val});
        else
            if (val < vec[vec.size()-1].second)
                vec.push_back({val, val});
            else
                vec.push_back({val, vec[vec.size()-1].second});
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec[vec.size()-1].first;
    }
    
    int getMin() {
        return vec[vec.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */