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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *temp = head;
        int len = 1;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        ListNode *last = temp;
        k = k%len;
        if(k==0) return head;
        len = len - k;
        temp = head;
        while(len>1){
            temp = temp->next;
            len--;
        }
        ListNode *teamHead = temp->next;
        temp->next = NULL;
        last->next = head;
        return teamHead;
        
    }
};