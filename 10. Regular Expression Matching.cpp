class Solution {
public:
    /*
     dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
     dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;
     dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 time.
    */

    bool doit(string s,string p,int m,int n)
    {
     bool dp[m+1][n+1];
     dp[0][0]=1;
     bool ff=0;
     for(int i=1;i<=n;i++)
     {
      if(p[i-1]=='*')
          dp[0][i]=dp[0][i-2];
      else
          dp[0][i]=0;
     }
     for(int i=1;i<=m;i++)
         dp[i][0]=0;
     for(int i=1;i<=m;i++)
     {
      for(int j=1;j<=n;j++)
      {
       if(s[i-1]==p[j-1] || p[j-1]=='.')
           dp[i][j]=dp[i-1][j-1];
       else if(p[j-1]=='*')
           dp[i][j]=dp[i][j-2] || (dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
       else
           dp[i][j]=0;
      }
     }
     return dp[m][n];
    }
    bool isMatch(string s, string p)
    {
     int m=s.length(),n=p.length();
     if(m==0 && n==0)return true;
     if(m!=0 && n==0)return false;
     return doit(s,p,m,n);
    }
};

// s=xaabyc
// p=xa*b.c
// o/p-True
