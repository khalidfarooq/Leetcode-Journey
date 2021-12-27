class Solution {
public:
    int findComplement(int num) {
        long long k = log2(num) + 1;
        cout<<k<<endl;
        return pow(2,k) - num - 1;
    }
};