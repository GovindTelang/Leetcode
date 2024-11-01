class Solution {
public:
    string makeFancyString(string s) {
        string v = "";
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(!v.empty() && c>1 && v[c-1]==v[c-2] && v[c-1]==s[i]){
                continue;
            }
            else{
                v += s[i];
                c++;
            }
        }
        return v;
    }
};
