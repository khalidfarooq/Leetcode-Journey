class Solution {
public:
	string addBinary(string a, string b) {
		if(a.size()<b.size()) return addBinary(b,a);
		int n=a.size();
		int m=b.size();
    
    int i=n-1,j=m-1;
    bool carry=false;
    while(i>=0 && j>=0){
        
        if(a[i]=='0' && b[j]=='0'){
            
            if(carry){
                a[i]='1';
                carry=false;
            }
            
        }
        else if(a[i]=='1' && b[j]=='1'){
            
            if(carry){
                a[i]='1';
                
                

            }
            else{
                a[i]='0';
                carry=true;
            }
            
        }
        else if(a[i]!=b[j]){
            
            if(carry){
                
                a[i]='0';
                
            }
            else{
                a[i]='1';
            }
            
        }
        i--;
        j--;
    }

   while(carry){
       if(i>=0){
           if(a[i]=='1'){
               a[i]='0';
               i--;
           }
           else{
               a[i]='1';
               carry=false;
           }
       }
       else{
           a='1'+a;
           carry=false;
           
       }
       
       
   }
    return a;
    

}
};