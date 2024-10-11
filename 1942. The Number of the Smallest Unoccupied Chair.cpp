class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
     int n = times.size();
     int tararrival = times[targetFriend][0];
     vector<int> endTimes(n,-1);
     sort(times.begin(),times.end());
     for(auto it : times){
        int arrival = it[0];
        int depart = it[1];
        for(int i=0;i<n;i++){
        if(endTimes[i] <= arrival){
            endTimes[i]=depart;
            if(arrival == tararrival) return i;
            break;
        }
        }
     }
     return -1;
    }
};
