// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node *reverse(struct Node *head){
        struct Node *prev = NULL, *curr = head;
        
       while(curr != NULL){ 
            struct Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
       }
       return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node *t1 = first,*t2 = second;
        t1 = reverse(t1);
        t2 = reverse(t2);
        
        struct Node *dummy = new Node(0);
        struct Node *t = dummy;
        int carry = 0;
        while(t1 != NULL || t2 != NULL || carry != 0){
            int curr = 0;
            int sum = 0;
            if(t1 != NULL){
                curr += t1->data;
                t1 = t1->next;
            }if(t2 != NULL){
                curr += t2->data;
                t2 = t2->next;
            }
            curr += carry;
            struct Node *newnode = new Node(curr%10);
            t->next = newnode;
            t = t->next;
            carry = curr/10;
        }
        t = dummy;
        dummy = dummy->next;
        delete t;
        return reverse(dummy);
       
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends