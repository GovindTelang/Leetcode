class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       int n = A.size();
       vector<int> ans(n);
       vector<int> v(n+1,0);
       int counter = 0;
       for(int i=0;i<n;i++){
        if(++v[A[i]] == 2) counter++;
        if(++v[B[i]] == 2) counter++;
        // note ki dono main se keval ek hi jagah counter++ hoga kisi bhi case main
        ans[i] = counter;
       }
       return ans; 
    }
};
