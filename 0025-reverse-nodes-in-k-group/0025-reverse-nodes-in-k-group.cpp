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
    ListNode* getkthnode(ListNode* temp,int k){
        k--;
        while(temp!=nullptr&&k>0){
            k--;
            temp=temp->next;
            
        }
        return temp;
    }

    ListNode* reverselist(ListNode* temp){
        ListNode* curr = temp;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            ListNode* front = curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        ListNode * prev = nullptr;
        while(temp!=nullptr){
            ListNode *kthnode = getkthnode(temp,k);
            if(kthnode==nullptr){
                if(prev!=nullptr){
                    prev->next=temp;
                }
                break;
            }
            ListNode * nextnode = kthnode->next;
            kthnode->next = nullptr;
            reverselist(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prev->next = kthnode;
            }
            prev = temp;
            temp = nextnode;

        }
        return head;
        
    }
};