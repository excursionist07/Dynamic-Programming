class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
     int m=matrix.size();
     if(m==0)return 0;
     int n=matrix[0].size();
     int dp[m][n];
     dp[0][0]=matrix[0][0]-'0';
    // cout<<dp[0][0]<<"\n";
     for(int i=1;i<n;i++)
         dp[0][i]=matrix[0][i]-'0';
     for(int i=1;i<m;i++)
         dp[i][0]=matrix[i][0]-'0';
     for(int i=1;i<m;i++)
     {
      for(int j=1;j<n;j++)
      {
       if(matrix[i][j]=='1')
           dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
       else
           dp[i][j]=0;
      }
     }
     int maxx=0;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       maxx=max(maxx,dp[i][j]);
      }
     }
        return maxx*maxx;
    }
};
