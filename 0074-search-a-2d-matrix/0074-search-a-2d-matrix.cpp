class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int i,j, a,b, temp, mid_row;
        //a,b: binary search ifor target row.
        //i,j: finding target in row.
        a=0;
        b=matrix.size()-1;//no. of rows in matrix
        temp=matrix[0].size(); //no. of columns in matrix.
        while(a<=b){
            mid_row=floor((a+b)/2);
            if(matrix[mid_row][0]<=target && matrix[mid_row][temp-1]>=target){
                break;
            }
            else if(target>matrix[mid_row][temp-1]){
                a=mid_row+1;
            }
            else if(target<matrix[mid_row][0]){
                b=mid_row-1;
            }
        }
        //now mid_row is the target row to find our target.
        i=0;
        j=temp-1;
        while(i<=j){
            int mid=floor((i+j)/2);
            if(matrix[mid_row][mid]==target){
                return true;
            }
            else if( target>matrix[mid_row][mid]){
                i=mid+1;
            }
            else if( target<matrix[mid_row][mid]){
                j=mid-1;
            }
        }
        return false;
    }
        
    };
