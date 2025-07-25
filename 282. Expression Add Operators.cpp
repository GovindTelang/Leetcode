class Solution {
public:
    vector<string> result;

    void backtrack(string &num, int target, int idx, long currEval, long prevOperand, string path) {
        if (idx == num.size()) {
            if (currEval == target) result.push_back(path);
            return;
        }

        for (int i = idx; i < num.size(); ++i) {
            // Avoid numbers with leading zero
            if (i != idx && num[idx] == '0') break;

            string currStr = num.substr(idx, i - idx + 1);
            long currNum = stol(currStr);

            if (idx == 0) {
                // First number, can't add operator before it
                backtrack(num, target, i + 1, currNum, currNum, currStr);
            } else {
                // +
                backtrack(num, target, i + 1, currEval + currNum, currNum, path + "+" + currStr);

                // -
                backtrack(num, target, i + 1, currEval - currNum, -currNum, path + "-" + currStr);

                // *
                backtrack(num, target, i + 1, currEval - prevOperand + prevOperand * currNum,
                          prevOperand * currNum, path + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};
