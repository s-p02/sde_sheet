class Solution {
public:
    int cntpaths(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up= cntpaths(i-1,j,obstacleGrid,dp);
        int left= cntpaths(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return cntpaths(m-1,n-1,obstacleGrid,dp);
    }
};

//Recursive:
// class Solution {
// public:
//     int cntpaths(int i,int j,vector<vector<int>>& obstacleGrid){
//         if(i<0 || j<0) return 0;
//         if(obstacleGrid[i][j]==1) return 0;
//         if(i==0 && j==0) return 1;
//         int up= cntpaths(i-1,j,obstacleGrid);
//         int left= cntpaths(i,j-1,obstacleGrid);
//         return up+left;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m= obstacleGrid.size();
//         int n= obstacleGrid[0].size();
//         //vector<vector<int>> dp(m,vector<int>(n,0));
//         return cntpaths(m-1,n-1,obstacleGrid);
//     }
// };