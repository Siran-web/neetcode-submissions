class MinStack {
public:
    vector<int> vec;
    vector<int> mini;

    MinStack() {}

    void push(int val) {
        vec.push_back(val);
        if (mini.empty() || val <= mini.back()) {
            mini.push_back(val);
        }
    }

    void pop() {
        if (vec.back() == mini.back()) {
            mini.pop_back();
        }
        vec.pop_back();
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        return mini.back();
    }
};
