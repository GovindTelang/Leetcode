class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        vector<string> vec;
        for(int i=0;i<31;i++){
            int x = pow(2,i);
            vec.push_back(to_string(x));
        }
        for(int i=0;i<31;i++){
            sort(vec[i].begin(),vec[i].end());
            if(vec[i]==s) return true;
        }
        return false;
    }
};
