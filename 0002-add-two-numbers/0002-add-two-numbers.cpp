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
    void reverse(ListNode* & head){
        ListNode* temp=head;
        ListNode* past=NULL;
        ListNode* headNext=NULL;

        while (temp!=NULL){
            headNext=temp->next;
            temp->next=past;
            past=temp;
            temp=headNext;
        }
        head=past;
    }

    void insertAtTail(ListNode* &head, ListNode* &tail, int data){
        ListNode* newNode=new ListNode(data);
        if (head==NULL){
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

        int carry=0;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        int sum=0;

        while (l1!=NULL || l2!=NULL || carry!=0){
            int firstVal=0;
            if (l1!=NULL) firstVal=l1->val;
            int secondVal=0;
            if (l2!=NULL) secondVal=l2->val; 

            sum=firstVal+secondVal+carry;
            carry=sum/10;
            insertAtTail(head, tail, (sum%10));
            if (l1!=NULL)
            l1=l1->next;
            if(l2!=NULL)
            l2=l2->next;
        }
        
        return head;
    }
};