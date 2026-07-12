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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL)
        return list2;

        if (list2==NULL)
        return list1;

        ListNode* curr=list1;
        ListNode* temp=list2;
        ListNode* tempNext=NULL;
        ListNode* prev=NULL;

        while (curr!=NULL && temp!=NULL){
            if (temp->val>curr->val){
                prev=curr;
                curr=curr->next;
            }
            else if (temp->val<=curr->val){
                if(curr==list1){
                    tempNext=temp->next;
                    prev=temp;
                    temp->next=curr;
                    temp=tempNext;
                    list1=prev;
                }
                else{
                    tempNext=temp->next;
                    prev->next=temp;
                    temp->next=curr;
                    prev=temp;
                    temp=tempNext;
                }
            }
        }

        if (temp!=NULL){
            prev->next=temp;
        }
        return list1;
    }
};