class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])) st.push(s[i]);
            else if(!st.empty()) st.pop();
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans = ch + ans;
        }
        return ans;
    }
};
