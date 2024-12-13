class cmp
{
    public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;
        vector<bool> mark(nums.size(),false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(!pq.empty()){
            int element = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if(!mark[index]){
             res += element;
             mark[index]=true;
             if(index-1>=0 && !mark[index-1]) mark[index-1]=true;
             if(index+1<nums.size() && !mark[index+1]) mark[index+1]=true;
            }
        }
        return res;
    }
};
