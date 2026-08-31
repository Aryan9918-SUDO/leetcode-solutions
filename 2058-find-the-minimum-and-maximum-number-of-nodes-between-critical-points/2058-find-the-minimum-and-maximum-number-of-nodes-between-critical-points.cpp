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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev= head;
        ListNode * curr = prev->next;

        int firstcritical = -1;
        int lastcritical = -1;
        int index = 1;
        int mindistance = INT_MAX;

        while(curr->next!=nullptr){
            ListNode* next = curr->next;

            bool iscritical = ((prev->val<curr->val && curr->val>next->val)
            ||(curr->val<prev->val && curr->val<next->val));
            
            if(iscritical){
                if(firstcritical ==-1){
                   firstcritical=index;
                }
                else{
                    mindistance = min(mindistance, index-lastcritical);
                }
                lastcritical=index;
                
            }
            
            prev =curr;
            curr = next;
            index++;
        }
        if(firstcritical==lastcritical){
            return{-1,-1};
        }
        int maxdistance = lastcritical-firstcritical;
        return {mindistance,maxdistance};

        
    }
};