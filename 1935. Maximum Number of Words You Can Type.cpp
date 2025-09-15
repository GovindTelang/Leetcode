class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<char> st;
    for(int i=0;i<brokenLetters.size();i++){
        st.insert(brokenLetters[i]);
    }
    int cnt = 0;
    stringstream ss(text);
    string word;
    while(ss >> word){
        bool flag = false;
        for(auto it : word){
            if(st.find(it)!=st.end()){
                flag = true;
                break;
            }
        }
        if(!flag) cnt++;
    }
    return cnt;
    }
};
