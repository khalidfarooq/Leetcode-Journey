// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        if(head->next == NULL){
            head->data++;
            return head;
        }
        
        Node *sum = addOne(head->next);
        head->data += (sum->data/10);
        sum->data = sum->data%10;
        return head;
        // if(head->next == NULL){
        //     head->data++;
        //     return head;
        // }
        
        // Node *end = head;
        // bool isNine = false;
        // while(end->next != NULL) 
        //     end = end->next;
        
        // if(end->data == 9) isNine = true;
        
        // if(!isNine){
        //     end->data++;
        //     return head;
        // }
        
        // Node *nineHead=head, *nineTail = head;
        // while(nineHead != end){
        //     nineHead = nineHead->next;
        //     if(nineHead->data == 9){
        //         nineTail = nineHead;
        //         while(nineHead->data == 9 && nineHead != end) 
        //             nineHead = nineHead->next;
        //     }
        // }
        
        // Node *temp = head;
        // while(temp->next != nineTail)
        //     temp = temp->next;
        
        // temp->data++;
        // temp = temp->next;
        // while(temp!=NULL){
        //     temp->data = 0;
        //     temp = temp->next;
        // }
    
        // return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends