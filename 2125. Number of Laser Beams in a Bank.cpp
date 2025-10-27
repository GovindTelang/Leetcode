class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int prev = 0;
       int ans = 0;
       for(string &str : bank){
        int count = 0;
        for(char c : str){
            if(c == '1') count++;
        }
        if(count!=0){
            ans += (prev*count);
            prev = count;
        } 
       }
       return ans; 
    }
};
