// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int count(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        ++count;
        temp = temp->next;
    }
    return count;
}
int intersectPoint(Node* head1, Node* head2)
{
    int l1 = count(head1), l2 = count(head2);
    int d = 0;
    Node *p1, *p2;
    if(l1>l2){
        d = l1-l2;
        p1 = head1;
        p2 = head2;
    }else{
        d= l2-l1;
        p1 = head2;
        p2 = head1;
    }
    
    while(d){
        p1 = p1->next;
        if(p1 == NULL) return -1;
        --d;
    }
    
    while(p1 != NULL && p2 != NULL){
        if(p1 == p2) return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
    // stack<Node*> s1,s2;
    // Node *temp;
    // temp = head1;
    // while(temp != NULL){
    //     s1.push(temp);
    //     temp = temp->next;
    // }
    // temp = head2;
    // while(temp != NULL){
    //     s2.push(temp);
    //     temp = temp->next;
    // }
    // while(s1.top() == s2.top()){
    //     temp = s1.top();
    //     s1.pop();
    //     s2.pop();
    //     if(s1.empty() || s2.empty()) break;
    // }
    // return temp->data;
}

