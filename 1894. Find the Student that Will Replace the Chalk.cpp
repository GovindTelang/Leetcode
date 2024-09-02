class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(int x : chalk){
            sum += x;
        }
        int a = k % sum;
        for(int i=0;i<n;i++){
            if(a < chalk[i]){
                return i;
            }
            a -= chalk[i];
        }
        return -1;
    }
};
