class Solution {
public:
    bool isCircularSentence(string sen) {
        int n = sen.size();
        int i = 0;
        while(i<n-1){
            if(sen[i]!=' '){
                i++;
                continue;
            } 
            else if(sen[i-1]==sen[i+1]){
                i++;
                continue;
            }
            else return false;
        }
        return sen[0]==sen[n-1];
    }
};
