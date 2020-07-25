class Solution {
public:
    bool doit(string s,string p,int m,int n)
    {

     bool dp[m+1][n+1];
     dp[0][0]=1;
     bool ff=0;
     for(int i=1;i<=n;i++)
     {
      if(!ff && p[i-1]=='*')
          dp[0][i]=1;
      else
          dp[0][i]=0,ff=1;
     }
     for(int i=1;i<=m;i++)
         dp[i][0]=0;
     for(int i=1;i<=m;i++)
     {
      for(int j=1;j<=n;j++)
      {
       if(s[i-1]==p[j-1] || p[j-1]=='?')
           dp[i][j]=dp[i-1][j-1];
       else if(p[j-1]=='*')
           dp[i][j]=dp[i-1][j] || dp[i][j-1];// dp[i][j-1]=(*=empty) && dp[i-1][j]=(*=Not empty)
       else
           dp[i][j]=0;//s[i-1]!=p[j-1]
      }
     }
     return dp[m][n];
    }
    bool isMatch(string s, string p)
    {
     int m=s.length(),n=p.length();
     if(m==0 && n==0)
         return true;
     if(m!=0 && n==0)
         return false;
     return doit(s,p,m,n);
    }
};
