class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long n = skill.size();
        long long sum = accumulate(skill.begin(),skill.end(),0);
        if(sum%(n/2) != 0) return -1;
        long long team = (sum/(n/2));
        sort(skill.begin(),skill.end());
        long long chemistry = 0;
        for(long long i = 0;i < n/2; i++){
        long long target = skill[i]+skill[n-i-1];
        if(target!=team) return -1;
        chemistry += skill[i]*skill[n-i-1];
        }
        return chemistry;

    }
};
