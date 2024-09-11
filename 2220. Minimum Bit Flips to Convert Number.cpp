class Solution {
public:
    int minBitFlips(int start, int goal) {
    int ans = 0;
    while(start>0 || goal>0){ //dono jab tak 0 nhi ho jaate tab tak
        if((1 & start)!=(1 & goal)) ans++;
        start>>=1;
        goal>>=1;
    }
    return ans;
    }
};
