class Solution {
public:
    /*void backtrack(vector<vector<int>>& matrix,int row, int col){
        
        if(row == -1 || col == -1 || row >= matrix.size() || col >= matrix[0].size()) return;
 
        matrix[row][col] = 0;
        
        if(row != 0) backtrack(matrix,row-1,col);//up
        if(row != matrix.size()-1) backtrack(matrix,row+1,col);//down
        if(col != 0) backtrack(matrix,row,col+1);//left
        if(col != matrix[0].size()-1) backtrack(matrix,row,col-1);//right
        
    }*/
    
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int col0 = 1;
        for(int i=0; i<n; i++){
            if(mat[i][0] == 0) col0=0;
            for(int j=1; j<m; j++){
                if(mat[i][j] == 0)   
                    mat[i][0] = mat[0][j] = 0;           
            }
        }
        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=1 ; j--){
                if(mat[i][0] == 0|| mat[0][j] == 0) 
                    mat[i][j] = 0;
            }
            if(col0 == 0) mat[i][0] = 0;
        }
        
    }
};