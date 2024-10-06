class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
    deque<string> dq1;
    deque<string> dq2;
    if(s1.length()>s2.length()) swap(s1,s2);
    stringstream ss1(s1);
    stringstream ss2(s2);
    string token;
    while(ss1 >> token){
        dq1.push_back(token);
    }   
    while(ss2 >> token){
        dq2.push_back(token);
    }   
    while(!dq1.empty() && !dq2.empty() && dq1.front()==dq2.front()){
        dq1.pop_front();
        dq2.pop_front();
    }
    while(!dq1.empty() && !dq2.empty() && dq1.back()==dq2.back()){
        dq1.pop_back();
        dq2.pop_back();
    }
    return dq1.empty();
    }
};
