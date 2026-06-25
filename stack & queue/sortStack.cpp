class Solution {
public:
    void correct(stack<int>& st, int top) {
        if (st.empty() || st.top() < top) {
            st.push(top);
            return;
        }

        int elem = st.top();
        st.pop();

        correct(st, top);

        st.push(elem);
    }

    void sortStack(stack<int>& st) {
        if (st.empty()) {
            return;
        }

        int top = st.top();
        st.pop();

        sortStack(st);

        correct(st, top);
    }
};