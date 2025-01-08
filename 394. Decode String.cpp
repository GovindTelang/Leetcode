class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;  // To store the repeat counts
        stack<string> strStack;  // To store the intermediate results
        string current = "";  // Current decoded string
        int num = 0;  // Current repeat count

        for (char ch : s) {
            if(isdigit(ch)) {
                // Build the number for the repeat count
                num = num * 10 + (ch - '0');
            } else if (ch == '[') {
                // Push current string and count to stacks
                numStack.push(num);
                strStack.push(current);
                // Reset for the new scope
                num = 0;
                current = "";
            } else if (ch == ']') {
                // Pop from stacks and decode the current string
                int repeat = numStack.top();
                numStack.pop();
                string previous = strStack.top();
                strStack.pop();

                // Append the repeated current string to the previous
                string repeated;
                for (int i = 0; i < repeat; i++) {
                  repeated += current;
                }
                current = previous + repeated;
            } else {
                // Append characters to the current string
                current += ch;
            }
        }
        return current;
    }
};
