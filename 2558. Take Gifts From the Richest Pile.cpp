class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());
        long long ans = 0;
        while(k--){
        int it = pq.top();
        pq.pop();
        int x = sqrt(it);
        pq.push(x);
        }
        while(!pq.empty()){
            int y = pq.top();
            pq.pop();
            ans += y;
        }
        return ans;
    }
};
