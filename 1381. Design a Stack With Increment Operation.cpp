class CustomStack {
public:
    vector<int> st;
    int max;
    CustomStack(int maxSize) {
        max = maxSize;
    }
    
    void push(int x) {
        if(st.size()>=max) return;
        st.push_back(x);
    }
    
    int pop() {
        if(st.size()==0) return -1;
        int x = st.back();
        st.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        int limit = k;
        if(st.size()<k) limit = st.size();
        for(int i=0;i<limit;i++){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
