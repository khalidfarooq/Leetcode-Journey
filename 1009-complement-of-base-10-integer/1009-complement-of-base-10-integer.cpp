class Solution {
public:
    int bitwiseComplement(int n) {
        return n>0 ? (int)((1ll<<((int)log2(n)+1)) - 1) ^ n : 1;
    }
};