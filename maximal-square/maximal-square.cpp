class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = row > 0 ? matrix[0].size() : 0;
        int maxSqLen = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '1'){
                    int currSqLen = 1;
                    bool flag = true;
                    while(currSqLen+i < row && currSqLen+j < col && flag){
                        for(int k = j; k <= currSqLen+j; k++){
                            if(matrix[i+currSqLen][k] == '0'){
                                flag = false;
                                break;
                            }
                        }
                        for(int k = i; k <= currSqLen+i; k++){
                            if(matrix[k][j+currSqLen] == '0'){
                                flag = false;
                                break;
                            }
                        }
                        if(flag) currSqLen++;
                        
                    }
                    if(maxSqLen<currSqLen) maxSqLen = currSqLen;
                }
            }
        }
        return maxSqLen*maxSqLen;
    }
};