class Solution {
public:
    vector<int> solve(string s){
       vector<int> result;
       int n = s.size();
       for(int i=0;i<n;i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
        vector<int> left = solve(s.substr(0,i));
        vector<int> right = solve(s.substr(i+1));
        for(int &x : left){
            for(int &y : right){
                if(s[i]=='+'){
                    result.push_back(x+y);
                }
                else if(s[i]=='-'){
                    result.push_back(x-y);
                }
                else{
                    result.push_back(x*y);
                }
            }
        }
        }
       }
       if(result.size()==0){
        int x = stoi(s);
        result.push_back(x);
       }
       return result; 
    }
    vector<int> diffWaysToCompute(string expression) {
      return solve(expression);
    }
};
