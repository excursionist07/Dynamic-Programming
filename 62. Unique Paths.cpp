class Solution {
public:
    /*int doit(int m,int n)
    {
     if(m==1 || n==1)
         return 1;
     return doit(m-1,n)+doit(m,n-1)//+doit(m-1,n-1) if diagonal movements are allowed;
    }*/
    int uniquePaths(int m, int n)
    {
     int dp[m][n];
     for(int i=0;i<m;i++)
         dp[i][0]=1;
     for(int i=1;i<n;i++)
         dp[0][i]=1;
     for(int i=1;i<m;i++)
     {
      for(int j=1;j<n;j++)
          dp[i][j]=dp[i-1][j]+dp[i][j-1];
     }
     return dp[m-1][n-1];
    }
};
