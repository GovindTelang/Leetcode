class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<P,vector<P>,greater<P>> pq;
      int mini,maxi=INT_MIN;
      //insert first element of each row into heap
      for(int i=0;i<nums.size();i++){
          pq.push({nums[i][0],{i,0}});
          maxi=max(maxi,nums[i][0]);
      }
      mini=pq.top().first;
      vector<int> ans(2);
      ans[0]=mini;
      ans[1]=maxi;
      P temp;
      int elem,row,col;
      while(pq.size()==nums.size()){
          temp = pq.top();
          pq.pop();
          elem=temp.first;
          row=temp.second.first;
          col=temp.second.second;
          if(col+1<nums[row].size()){
              col++;
              pq.push({nums[row][col],{row,col}});
              maxi=max(maxi,nums[row][col]);
              mini=pq.top().first;
              if(maxi-mini < ans[1]-ans[0]){
                  ans[0]=mini;
                  ans[1]=maxi;
              }
          }
      }
      return {ans[0],ans[1]};
    }
};
