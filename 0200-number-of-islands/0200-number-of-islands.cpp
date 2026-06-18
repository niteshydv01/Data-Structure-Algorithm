class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>& grid,int delr[],int delc[]){
        vis[r][c]=1;
         int n=grid.size();
         int m=grid[0].size();
        for(int i=0;i<4;i++){
            int row=r+delr[i];
            int col=c+delc[i];

            if(row >= 0 && row < n &&
                    col >= 0 && col < m &&
                    !vis[row][col] &&
                    grid[row][col] == '1')
                    {
                        dfs(row,col,vis,grid,delr,delc);
}
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int ilands=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int delr[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&& grid[i][j]=='1'){
                    dfs(i,j,vis,grid,delr,dcol);
                    ilands++;
                }
            }
        }

        return ilands;
        
    }
};