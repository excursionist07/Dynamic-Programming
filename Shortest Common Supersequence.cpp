class Solution {
public:
    string scs(string str1,string str2,int m,int n)
    {
     int dp[m+1][n+1];
     for(int i=0;i<=n;i++)
         dp[0][i]=i;
     for(int i=1;i<=m;i++)
         dp[i][0]=i;
     for(int i=1;i<=m;i++)
     {
      for(int j=1;j<=n;j++)
      {
       if(str1[i-1]==str2[j-1])
           dp[i][j]=1+dp[i-1][j-1];
       else
           dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
      }
     }
     string ans="";
     int i=m,j=n;
     while(i>0 && j>0)
     {
      if(str1[i-1]==str2[j-1])
      {
       ans+=str1[i-1];
       i--;
       j--;
      }
      else if(dp[i-1][j]<dp[i][j-1])
      {
       ans+=str1[i-1];
       i--;
      }
      else
      {
       ans+=str2[j-1];
       j--;
      }
     }
     while(i>0)
     {
      ans+=str1[i-1];
      i--;
     }
      while(j>0)
     {
      ans+=str2[j-1];
      j--;
     }
     reverse(ans.begin(),ans.end());
     return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) 
    {
     int m=str1.length();
     int n=str2.length();
     if(m==0)
         return str2;
     if(n==0)
         return str1;
     return scs(str1,str2,m,n);
    }
};
