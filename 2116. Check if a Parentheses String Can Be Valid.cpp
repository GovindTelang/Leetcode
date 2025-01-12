class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2) return 0;
        stack<int> openBr,unlocked;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                unlocked.push(i);
            }
            else if(s[i]=='('){
                openBr.push(i);
            }
            else if(s[i]==')'){
                if(openBr.empty()==false){
                    openBr.pop();
                }
                else if(unlocked.empty()==false){
                    unlocked.pop();
                }
                else return false;
            }
        }
        while(!unlocked.empty() && !openBr.empty() && openBr.top()<unlocked.top()){
            openBr.pop();
            unlocked.pop();
        }
        if(!openBr.empty()) return false;
        return true;
    }
};
