class Solution {
public:
    string removeStars(string s) {
    stack<char> st;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]!='*') st.push(s[i]);
        else if(!st.empty() && s[i]=='*'){
            st.pop();
        }
    }
    string snew = "";
    while(!st.empty()){
        snew += st.top();
        st.pop();
    } 
    reverse(snew.begin(),snew.end());
    return snew;   
    }
};
