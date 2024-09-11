class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
    int ans = 0;
    sort(people.begin(),people.end());
    int l = 0;
    int r = n-1;
    while(l<=r){
    int sum = people[l]+people[r];
    if(sum<=limit){
        ans++;
        l++;
        r--;
    }
    else{
        ans++;
        r--;  //greedily bade walo ko khatam kr rhe so that do do ke pair bana paae
    }
    }
    return ans;
    }
};
