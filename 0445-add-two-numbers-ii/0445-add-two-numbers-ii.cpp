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
    private:
    void reverse(ListNode* &head){
        ListNode* temp=head;
        ListNode* tempNext=NULL;
        ListNode* prev=NULL;

        while (temp!=NULL){
            tempNext=temp->next;
            temp->next=prev;
            prev=temp;
            temp=tempNext;
        }
        head=prev;
    }
    void InsertAtTail(ListNode* &head, ListNode* &tail, int data){
        ListNode* newNode=new ListNode(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverse(l1);
        reverse(l2);

        int carry=0;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while (l1!=NULL || l2!=NULL || carry!=0){
            int firstVal=0;
            if (l1!=NULL) firstVal=l1->val;
            int secondVal=0;
            if(l2!=NULL) secondVal=l2->val;

            int sum=firstVal+secondVal+carry;
            carry=sum/10;
            InsertAtTail(head, tail, (sum%10));
            if (l1!=NULL) l1=l1->next;
            if (l2!=NULL) l2=l2->next;
        }
        reverse (head);
        return head;
    }
};