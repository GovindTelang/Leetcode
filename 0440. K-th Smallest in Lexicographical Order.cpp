class Solution {
public:
     long long countNodesWithPrefix(long long curr, int n) {
        long long count = 0;
        long long first = curr, last = curr;
        
        while (first <= n) {
            count += min((long long)n, last) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }
        
        return count;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;  // as we have already counted 1
        
        while (k > 0) {
            long long number_of_nodes_with_prefix_curr = countNodesWithPrefix(curr, n);
            
            if (number_of_nodes_with_prefix_curr <= k) {
                k -= number_of_nodes_with_prefix_curr;
                curr++;  // move to the next prefix
            } else {
                k--;  // move to the next level in the lexicographical tree
                curr *= 10;
            }
        }
        
        return (int)curr;
    }
};

/*let’s take a specific example. Suppose we want to count how many numbers lie in the subtree rooted at 1 when n = 150.

We consider:

First = 1 (the smallest number starting with the prefix 1)
Last = 1 (the largest number starting with the prefix 1 that we can keep growing)
Now, we expand this range of numbers by multiplying the first and last by 10 at each step:

For First = 1, Last = 1, the numbers are 1 to 1 (just the number 1 itself).
Multiply by 10: First = 10, Last = 19, the numbers are 10 to 19 (all numbers from 10 to 19).
Multiply again: First = 100, Last = 199, the numbers would be 100 to 150, but since n = 150, we stop at 150. */
