class Solution {
public:
    bool canConstruct(string s, int k) {
       int n = s.size();
       if(n<k) return 0;
       if(n==k) return 1;
       vector<int> v(26,0);
       int odd = 0;
       for(char ch : s){
        v[ch-'a']++;
       }
       for(int i=0;i<26;i++){
        if(v[i]%2==1) odd++;
       }
       return odd <= k;
     /* in short
       if(odd>k) return 0;  //har ek odd frequency wale ko ek string deni padegi example aanann -> an'_'na ya toh n aaega ya a dono nhi aa skte toh jitne odd counts wale characters honge utni minimum strings lagegi hi so if they are greater than k then minimjm is greater than k
       return 1;*/

    }
};
