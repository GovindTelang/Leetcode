class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int len = 0;
        unordered_set<int> st;
        for(int num : arr1){
            while(!st.count(num) && num>0){
                st.insert(num);
                num /= 10;
            }
        }
        for(int a : arr2){
            while(!st.count(a) && a>0){
                a /= 10;
            }
            if(a>0){
                len = max(len,(int)(log10(a)+1));
            }
        }
        return len;
    }
};
