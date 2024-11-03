class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string help = s;
        help += s;
        if(help.find(goal) != string::npos) return true;
        return false;
    }
};
