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
    void add(int data, ListNode* &head, ListNode* &tail){
        ListNode* newNode=new ListNode(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        return;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL;
        ListNode* tail=NULL;

        while (list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                add(list1->val, head,tail);
                list1=list1->next;
            }
            else if (list2->val<list1->val){
                add(list2->val, head, tail);
                list2=list2->next;
            }
        }
        while (list1!=NULL){
            add(list1->val, head, tail);
            list1=list1->next;
        }
        while (list2!=NULL){
            add(list2->val, head, tail);
            list2=list2->next;
        }
        return head;
    }
};