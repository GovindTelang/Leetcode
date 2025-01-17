class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for(auto &elem : derived){
            XOR ^= elem;
        }
        return XOR == 0;
    }
};
