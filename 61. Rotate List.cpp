/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Find the length of the list and tail node
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: Make it a circular list
        tail->next = head;

        // Step 3: Find the new tail: len - (k % len) - 1
        // and new head: new_tail->next
        k = k % len;
        int stepsToNewHead = len - k;
        ListNode* newTail = tail;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }

        // Step 4: Break the cycle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead; 
    }
};
