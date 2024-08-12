class Solution {
public:
typedef pair<int,char> P;
    string frequencySort(string s) {
        priority_queue<P> pq;
        map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        /*for(int i=0;i<26;i++){ //this would have worked if capital alphabets are not used
            if(mp[i+'a']>0){
            pq.push({mp[i+'a'],i+'a'});
            }
        }*/
        for(auto it : mp){  //it is an iterator so using pq.push({mp[it],it}) is wrong
        pq.push({it.second,it.first}); //and no need to check for any if(it.second>0) if it 
        }                                // is presenty in the map that means that it exists
        string ans = "";
        while(!pq.empty()){
        int a = pq.top().first;
        while(a--)
        ans += pq.top().second;

        pq.pop();
        }
        return ans;
    }
};
