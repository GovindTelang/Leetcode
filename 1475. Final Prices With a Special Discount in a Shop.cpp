class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    for(int i=0;i<n;i++){
        int curr = prices[i];
        for(int j=i+1;j<n;j++){
            if(prices[j]<=curr){
                curr-=prices[j];
                break;
            }
        }
        prices[i]=curr;
    }
    return prices;    
    }
};
