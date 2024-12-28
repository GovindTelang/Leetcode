class Solution {
public:
    pair<int,int> extract(string s){
        int l = s.size();
        int a,b;
        int i=0;
        while(i<l && s[i]!='+'){
            i++;
        }
        a = stoi(s.substr(0,i));
        b = stoi(s.substr(i+1));
        return {a,b};
    }
    string complexNumberMultiply(string a, string b) {
        if(a=="") return b;
        if(b=="") return a;
        auto p1 = extract(a);
        auto p2 = extract(b);
        int x,y;
        x = p1.first*p2.first - p1.second*p2.second;
        y = p1.second*p2.first + p1.first*p2.second;
        string ans;
        ans = to_string(x)+"+"+to_string(y)+"i";
        return ans; 
    }
};
