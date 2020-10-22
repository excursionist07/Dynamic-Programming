// 44. Wildcard Matching

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

// 10. Regular Expression Matching

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

// 97. Interleaving String

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

