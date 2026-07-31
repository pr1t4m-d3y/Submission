/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode=new Node(data);
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
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;

        while (temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp=temp->next;
        }
        Node* cloneTemp=cloneHead;
        temp=head;
        Node* cloneTempNext=NULL;
        Node* tempNext=NULL;

        while (temp!=NULL){
            tempNext=temp->next;
            temp->next=cloneTemp;
            cloneTempNext=cloneTemp->next;
            cloneTemp->next=tempNext;
            temp=tempNext;
            cloneTemp=cloneTempNext;
        }
        temp=head;
        while (temp!=NULL){
            temp->next->random=(temp->random!=NULL)? temp->random->next: NULL;
            temp=temp->next->next;
        }
        temp=head;
        cloneTemp=cloneHead;
        while (cloneTemp!=NULL && temp !=NULL){
            temp->next=temp->next->next;
            cloneTemp->next=(cloneTemp->next!=NULL)?cloneTemp->next->next : NULL;
            temp=temp->next;
            cloneTemp=cloneTemp->next;
        }
        return cloneHead;
    }
};