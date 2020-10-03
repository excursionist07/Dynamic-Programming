class Solution {
public:
    int doit(string str)
    {
     int n=str.length();
     bool isPal[n][n];
     //int dp[n][n];
     memset(isPal,0,sizeof(isPal));
    /* for(int i=0;i<n;i++)//O(n^3)
     {
      dp[i][i]=0;
      isPal[i][i]=1;
     }
    for(int i=0;i<n-1;i++)
     {
      if(str[i]==str[i+1])
      {
       isPal[i][i+1]=1;
       dp[i][i+1]=0;
      }
      else
      {
       isPal[i][i+1]=0;
       dp[i][i+1]=1;
      }
     }
     for(int len=3;len<=n;len++)
     {
      for(int i=0;i<n-len+1;i++)
      {
       int j=i+len-1;
       isPal[i][j]=(isPal[i+1][j-1] && str[i]==str[j]);
       if(isPal[i][j])
           dp[i][j]=0;
       else
       {
         dp[i][j]=INT_MAX;
         for(int k=i;k<=j-1;k++)
             dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
       }
       
      }
     }
     return dp[0][n-1];*/
     int dp[n];
     for(int i=0;i<n;i++)
         isPal[i][i]=1;
     for(int len=2;len<=n;len++)
     {
      for(int i=0;i<n-len+1;i++)
      {
       int j=i+len-1;
       if(len==2)
           isPal[i][j]=(str[i]==str[j]);
       else
           isPal[i][j]=(isPal[i+1][j-1] && str[i]==str[j]);
      }
     }
     for(int i=0;i<n;i++)
     {
      if(isPal[0][i])
           dp[i]=0;
      else
       {
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++)
        {
         if(isPal[j+1][i])
             dp[i]=min(dp[i],1+dp[j]);
        }
       }
      
     }
     return dp[n-1];
     
    }
    int minCut(string s)
    {
     int n=s.length();
     if(n<=1)
         return 0;
     return doit(s);
    }
};
