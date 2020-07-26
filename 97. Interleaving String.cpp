class Solution {
public:
    bool doit(string s1,string s2,string s3,int n1,int n2,int n3)
    {
     bool dp[n1+1][n2+1];
     dp[0][0]=1;
     for(int i=1;i<=n2;i++)
     {
      if(s2[i-1]==s3[i-1] && dp[0][i-1])
          dp[0][i]=true;
      else
          dp[0][i]=false;
     }
      for(int i=1;i<=n1;i++)
     {
      if(s1[i-1]==s3[i-1] && dp[i-1][0])
          dp[i][0]=true;
      else
          dp[i][0]=false;
     }
     for(int i=1;i<=n1;i++)
     {
      for(int j=1;j<=n2;j++)
      {
       if(s3[i+j-1]==s1[i-1] && dp[i-1][j])
           dp[i][j]=true;
       else if(s3[i+j-1]==s2[j-1] && dp[i][j-1])
           dp[i][j]=true;
       else
           dp[i][j]=false;
      }
     }
     return dp[n1][n2];
    }
    bool isInterleave(string s1, string s2, string s3)
    {
     int n1=s1.length(),n2=s2.length(),n3=s3.length();
     if(n1+n2!=n3)
         return false;
     return doit(s1,s2,s3,n1,n2,n3);
    }
};
