class Solution {
public:
    vector<int> minOperations(string boxes) {
       vector<int> ans(boxes.length());
       for(int i=0;i<boxes.size();i++){
        if(boxes[i] == '1'){
            for(int j=0;j<boxes.size();j++){
                ans[j] += abs(j-i);              //boxes main 1 hn toh usko sab main bhejne main kitna lagege
            }
        }
       }
       return ans; 
    }
};
