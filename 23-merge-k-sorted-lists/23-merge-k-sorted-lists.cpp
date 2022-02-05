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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int>m;
        ListNode *t;
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                m.insert(temp->val);
                temp = temp->next;
            }
        }
        for(auto x : m){
            cout<<x<<endl;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *newHead = dummy;
        
        for(auto x : m){
            ListNode *newnode = new ListNode(x);
            newHead->next = newnode;
            newHead = newHead->next;
        }
        return dummy->next;
    }
};