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
        if(head==nullptr||head->next==nullptr){
            return true;
        }
        ListNode * slow = head;
        ListNode * fast = head->next;

        while(fast->next!=nullptr &&fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * prev = nullptr;
        ListNode * curr = slow->next;
        while(curr!=nullptr){
            ListNode * front = curr->next;
            curr->next = prev;
            prev = curr;
            curr=front;
        }
        ListNode * right = head;
        ListNode * left = prev;
        while(left!=nullptr){
            if(left->val!=right->val){
                return false;
            }
            left=left->next;
            right = right->next;
        }
        return true;
    }
};