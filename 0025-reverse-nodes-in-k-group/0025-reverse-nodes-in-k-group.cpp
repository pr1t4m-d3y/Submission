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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL)
        return NULL;


        ListNode* temp=head;
        int c=0;
        while (temp!=NULL && c<k){
            temp=temp->next;
            c++;
        }
        if(c<k)
        return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode*nex=NULL;

        int count=0;
        while (curr!=NULL && count<k){
            count++;
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }

        if (curr!=NULL)
        head->next=reverseKGroup(curr, k);

        return prev;
    }
};