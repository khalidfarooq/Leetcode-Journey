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
    int getDecimalValue(ListNode* head) {
        string binary_str = "";
        ListNode *t = head;
        while(t!=NULL){
            binary_str += to_string(t->val);
            t = t->next;
        }
        int k = binary_str.length()-1; // 3
        int res = 0;
        int i=0;
        for(int i=0; i<binary_str.length(); i++){
            int a = (binary_str[i] == '1') ? 1 : 0;
            cout<<pow(2,k)*a<<" ";
            res+=pow(2,k)*a;
            k--;
        }
        return res;
    }
};