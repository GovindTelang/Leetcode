class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 || k==1) return 0;
        return k <= pow(2,n-2) ? kthGrammar(n-1,k) : !kthGrammar(n-1,k-pow(2,n-2)); //when k is greater than pow(2,n-2) toh simple subtraction ho jaaega
    }
};
