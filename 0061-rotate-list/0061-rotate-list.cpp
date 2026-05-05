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
    int length(ListNode* head){
        if(head==NULL){
            return 0;
        }
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n=length(head);
        if(head==NULL||n==0||k==0||n==1||k%n==0){
            return head;
        }
        k=k%n;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr!=NULL){
            next=curr->next;
            curr->next = prev;
            prev=curr; 
            curr=next;    
        }
        head=prev;
        int st=0;
        ListNode* prev2 = nullptr;
        ListNode* curr2 = head;
        ListNode* next2 = nullptr;
        while(curr2!=NULL&&st<k){
            next2=curr2->next;
            curr2->next = prev2;
            prev2=curr2; 
            curr2=next2;
            st++;
        }
        ListNode* prev3 = nullptr;
        next2 = nullptr;
        while(curr2!=NULL){
            next=curr2->next;
            curr2->next = prev3;
            prev3=curr2; // prev 3 aglee halff ka haii 
            curr2=next;
        }
        head=prev2;
        
        while(prev2!=NULL&&prev2->next!=NULL){
            prev2=prev2->next;// prev 2 pehleee ko bacha ke le aaya 
        }
        if(prev2!=NULL){
            prev2->next=prev3;
        
        }
        return head;
    }
};