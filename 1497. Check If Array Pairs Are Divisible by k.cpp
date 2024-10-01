class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        int n = arr.size();
        for(int i=0;i<n;i++){
        freq[((arr[i]%k)+k)%k]++;
        }
        for(int x : arr){
        int rem = (x%k+k)%k; //this is to handle negative numbers 
        if(rem==0){
            if(freq[rem]!=0 && freq[rem]%2) return false;
        }
        else if(freq[rem]!=freq[k-rem]) return false;
        }
        return true;
    }
};
