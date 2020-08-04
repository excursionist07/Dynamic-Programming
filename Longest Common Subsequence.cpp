class Solution {
public:
    int lcs(string str1,string str2,int m,int n)
    {
     int dp[m+1][n+1];
     for(int i=0;i<=m;i++)
     {
      for(int j=0;j<=n;j++)
      {
       if(i==0 || j==0)
           dp[i][j]=0;
       else if(str1[i-1]==str2[j-1])
           dp[i][j]=1+dp[i-1][j-1];
       else
           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
     }
     
     /*
     string ans="";
     if(dp[m][n]!=0)
     {
      int i=m,j=n;
      while(i>0 && j>0)
      {
       if(str1[i-1]==str2[j-1])
       {
        ans+=str1[i-1];
        i--;
        j--;
       }
       else if(dp[i-1][j]>dp[i][j-1])
           i--;
       else j--;
      }
      reverse(ans.begin(),ans.end());
      cout<<ans;
     }
     */
     return dp[m][n];
    
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
     int m=text1.length();
     int n=text2.length();
     if(m==0 || n==0)
         return 0;
     return lcs(text1,text2,m,n);
    }
};
