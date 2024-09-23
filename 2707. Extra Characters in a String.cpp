class Solution {
public:
    //simple recursion and uska bottom up code using map hn but u can use dp array too.
    int solve(int i,string &s,unordered_set<string> &st,int &n,unordered_map<int,int> &mp){
        if(i>=n) return 0;
        if(mp.count(i)) return mp[i];
        int result = 1+solve(i+1,s,st,n,mp);
        for(int j=i;j<n;j++){ //j=i se isliye kyunki ho skta ek single character wala ho "l" 
            string curr = s.substr(i,j-i+1);
            //valid substring
            if(st.count(curr)){
            result = min(result,solve(j+1,s,st,n,mp));
            }
        }
        return mp[i]=result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        int n = s.size();
        unordered_map<int,int> mp;
        return solve(0,s,st,n,mp);
    }
};
