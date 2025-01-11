class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        long long ans=0;
        int prev[n],next[n];
        prev[0]=height[0];
        next[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            prev[i]=max(prev[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            next[i]=max(next[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
        ans += min(prev[i],next[i])-height[i]; 
        }
        return (int)ans;
    }
};
