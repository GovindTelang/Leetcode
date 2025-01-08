class Solution {
public:
    bool isPre(string &x,string &y){
        return y.find(x)==0;
    }
    //bool isSuff(string &x,string &y){   this will cause problems as you are actually changing the content of x and y and they could be used in future
    bool isSuff(string x,string y){
        reverse(y.begin(),y.end());
        reverse(x.begin(),x.end());
        return y.find(x)==0;
    }  
    int countPrefixSuffixPairs(vector<string>& words) {
       int ans = 0;
       int n = words.size();
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string x = words[i];
            string y = words[j];
            if(x.size()>y.size()) continue;
            if(isPre(x,y) && isSuff(x,y)) ans++;
            /* THIS ALSO WORKS INSTEAD OF THE FUNCTIONS
            if (str2.find(str1) == 0 &&
                    str2.rfind(str1) == str2.size() - str1.size()) {
                    ++count;
                }*/
        }
       }
       return ans; 
    }
};
