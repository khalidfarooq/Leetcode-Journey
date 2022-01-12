class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>&matrix) {
        vector<int>res;
        int row = matrix.size(), col = matrix[0].size();
        int rowMin = 0, colMin = 0;
        int rowMax = row-1, colMax = col-1;
        int limit = row*col;
        int count = 0;
        
        while(count < limit){
            //top wall
            for(int i=rowMin, j=colMin; j<=colMax && count<limit; ++j){
                res.push_back(matrix[i][j]);
                ++count;
            }
            ++rowMin;
            
            //side wall
            for(int i=rowMin, j=colMax; i<=rowMax && count<limit; ++i){
                res.push_back(matrix[i][j]);
                ++count;
            }
            --colMax;
            
            //bottom wall
            for(int i=rowMax, j=colMax; j>=colMin && count<limit; --j){
                res.push_back(matrix[i][j]);
                ++count;
            }
            --rowMax;
            
            for(int i=rowMax, j=colMin; i>=rowMin && count<limit; --i){
                res.push_back(matrix[i][j]);
                ++count;
            }
            colMin++;
        }
        return res;
    }
};