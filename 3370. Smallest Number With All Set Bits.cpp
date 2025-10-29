class Solution {
public:
    int smallestNumber(int n) {
        int k = ceil(log2(n + 1)); // Use n+1 here
        return (1 << k) - 1; 
    }
};
