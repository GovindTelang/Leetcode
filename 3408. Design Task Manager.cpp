class TaskManager {
public:
    typedef pair<int,int> p;
    set<p> st;
    unordered_map<int,p> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks){
            int pr = it[2];
            int uId = it[0];
            int tId = it[1];
    
            add(uId,tId,pr);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={userId,priority};
        st.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        p it = mp[taskId];
        st.erase({it.second,taskId});
        st.insert(make_pair(newPriority,taskId));
        
        mp[taskId]=make_pair(it.first,newPriority);
        
    }
    
    void rmv(int taskId) {
    auto x=mp[taskId];
    int pr=x.second;
    mp.erase(taskId);
     st.erase(make_pair(pr,taskId));
    }
    
    int execTop() {
        if(st.empty()) return -1;
        p x=*st.rbegin();
        int Tid=x.second;
        int Uid = mp[Tid].first;
        st.erase(x);
        mp.erase(Tid);
        return Uid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
