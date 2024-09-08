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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode * curr = head;
        int len = 0;
        while(curr){
        curr=curr->next;
        len++;
        }
        vector<ListNode*> ans(k,NULL);
        int totalperpart = len/k;
        int rem = len%k;
        curr = head;
        ListNode* prev = NULL;
        for(int i=0;i<k;i++){
            ans[i] = curr;
            for(int count = 0;count < totalperpart + (rem>0 ? 1 : 0);count++){
                prev = curr;
                curr=curr->next;
            }
            rem--;
            if(prev!=NULL) prev->next=NULL; // or simply add curr!=NULL so prev will not be updated as kuch parts null bhi honge see example 1 
        }
        return ans;
    }
};
