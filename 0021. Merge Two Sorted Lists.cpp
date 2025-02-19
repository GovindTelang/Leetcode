class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 ==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;
        while(list1 && list2){//traverse till one of the list in it gets empty
            if(list1->val <= list2->val){//if list 1 is value  smaller or equal than list2 current pointer
                mptr->next =list1;//point mptr to list1 
                list1=list1->next;//move list1 pointer one step ahead
            }
            else{
                mptr->next=list2;
                list2=list2->next;
            }
            mptr=mptr->next;//move mptr pointer one step ahead
        }
        if(list1) mptr->next=list1;//(list1's size > list2's size)
        if(list2) mptr->next=list2;//( "           <         "   )
        return ans->next;//in ans our first node  value is -1 our merged list will start from second node 
    }
};
