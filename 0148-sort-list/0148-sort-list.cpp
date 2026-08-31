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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode  dummynode(0);
        ListNode* temp = &dummynode;
        while(left!=nullptr && right !=nullptr){
            if(left->val<=right->val){
                temp->next=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right= right->next;
            }
            temp= temp->next;

        }
        if(left!=nullptr){
            temp->next=left;
        }
        else{
            temp->next=right;
        }
        return dummynode.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast=fast->next->next;
        }
        ListNode * right = slow->next;
        slow->next = nullptr;
        
        ListNode * left = sortList(head);
        right = sortList(right);

        return merge(left,right);
        
    }
};