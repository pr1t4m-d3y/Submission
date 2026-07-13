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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp=slow->next;
        ListNode* tempPast=NULL;
        ListNode* tempNext=NULL;
        while (temp!=NULL){
             if (temp->next==NULL){
                slow->next=temp;
            }
            tempNext=temp->next;
            temp->next=tempPast;
            tempPast=temp;
            temp=tempNext;
        }
        slow=slow->next;
        temp=head;
        while (slow!=NULL){
            if(slow->val!=temp->val)
            return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};