// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
   
    
    
    int kthSmallest(int arr[], int l, int r, int k) {
        // //code here
        
        
        priority_queue<int>pq;
        for(int i=l; i<=r; i++){
            pq.push(arr[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        
        // int &min = *min_element(arr,arr+r);
        // int &max = *max_element(arr,arr+r);
        
        // vector<int>range(max-min+1);
        
        // for(int i=0; i<r; i++){
        //     int x = arr[i]-min;
        //     range[x]++;
        // }
        // int j=0;
        // for(int i=0; i<range.size(); i++){
        //     if(range[i] != 0){
        //         range[j++] = i+min; 
        //     }
        // }
        // return range[k-1];
        
    }
   
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends