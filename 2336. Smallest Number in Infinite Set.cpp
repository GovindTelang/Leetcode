class SmallestInfiniteSet {
public:
    int current;
    set<int> s;
    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        if(s.empty()==false){
            int ans = *s.begin();
            s.erase(ans);
            return ans;
        }
        else{
            return current++;
        }
    }
    
    void addBack(int num) {
        if(num<current && s.find(num)==s.end()) s.insert(num);
    }
};
