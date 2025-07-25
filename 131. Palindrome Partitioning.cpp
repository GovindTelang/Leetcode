class Solution {
public:
    bool isPal(string str,int s,int e){
        while(s<=e){
            if(str[s++]!=str[e--]) return false;
        }
        return true;
    }
    void parthelp(int i,string s,vector<string> &path,vector<vector<string>> &res){
        if(i==s.size()){
            res.push_back(path);
            return;
        }
        for(int end = i;end < s.size();end++){
            if(isPal(s,i,end)){
                path.push_back(s.substr(i,end-i+1));
                parthelp(end+1,s,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      vector<string> path;
      parthelp(0,s,path,res);
      return res;  
    }
};
