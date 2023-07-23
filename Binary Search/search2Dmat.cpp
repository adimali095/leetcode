class Solution {
public:

    int getElement(int index,int cols,vector<vector<int>> & mat)
    {
        int row,col;
        row = index/cols;
        col = index%cols;
        return mat[row][col];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows,cols,length;
        rows = matrix.size();
        cols = matrix[0].size();
        length = cols;

        int low = 0,mid,high = rows*cols-1,element;
        while(low<=high)
        {
            mid = (low+high)/2;
            element = getElement(mid,length,matrix);
            cout<<element<<"\t";
            if(element == target)
            {
                return true;
            }
            else if(element > target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return false;
    }
};
