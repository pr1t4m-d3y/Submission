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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* temp=head->next;
        ListNode* curr=head;

        while (temp!=NULL){
            if (temp->val==curr->val) temp=temp->next;
            else{
                curr->next=temp;
                curr=temp;
                temp=temp->next;
            }
        }
        curr->next=NULL;
        return head;

    }
};