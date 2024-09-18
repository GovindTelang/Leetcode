bool comp(int &a,int &b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1+s2 > s2+s1;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
      /* vector<string> res;
       for(auto it : nums){
        res.push_back(to_string(it));
       }*/
       sort(nums.begin(),nums.end(),comp);
       string ans = "";
       for(auto ch : nums){
        ans += to_string(ch);
       } 
       return (ans.size()>1 && ans[0]=='0' ? "0" : ans);
    }
};
