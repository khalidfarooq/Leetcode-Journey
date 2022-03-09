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
        map<int,int>m;
        
        ListNode *tmp = head;
        while(tmp != NULL){
            m[tmp->val]++;
            tmp = tmp->next;
        };
        
        ListNode *dummy = new ListNode(0);
        ListNode *newHead = dummy;
        
        for(auto x : m){
            if(x.second > 1) continue;
            
            ListNode *tmp = new ListNode(x.first);
            newHead->next = tmp;
            newHead = newHead->next;
        }
        return dummy->next;
    }
};