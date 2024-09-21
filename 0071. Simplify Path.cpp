class Solution {
public:
    string simplifyPath(string path) {
     stack<string> st;
     string temp;
     stringstream ss(path);
     while(getline(ss,temp,'/')){
        if(temp.empty() || temp == ".") continue;
        else if(temp==".."){ //(temp==".." && !st.empty()) mat likhna warna else wale case ke thrgh stk main push ho jaaega ..
        if(!st.empty()){
            st.pop();
        }
     }
        else st.push(temp);
     }
     string res;
     while(!st.empty()){
        res = "/" + st.top() + res;
        st.pop();
     }
     return res.empty() ? "/" : res; 
    }
};
