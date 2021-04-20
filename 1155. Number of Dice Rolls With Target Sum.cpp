class Solution {
public:
    int numRollsToTarget(int d, int f, int target)
    {
     int dp[d+1][target+1];
     for(int i=0;i<=d;i++)
          for(int j=0;j<=target;j++)
               dp[i][j]=0;
     int fcb=1e9+7;
     for(int i=1;i<=f && i<=target;i++)
          dp[1][i]=1;
     for(int i=2;i<=d;i++)
     {
      for(int j=1;j<=target;j++)
      {
       for(int k=1;k<j && k<=f;k++)
       {
        dp[i][j]+=dp[i-1][j-k];
           dp[i][j]%=fcb;    
       }
                  
      }
             
     }
       
     return dp[d][target];
      
     
    }
};
