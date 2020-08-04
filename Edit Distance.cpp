class Solution {
public:
    int ed(string str1,string str2,int m,int n)
    {
     int dp[m+1][n+1];
     for(int i=0;i<=m;i++)
     {
      for(int j=0;j<=n;j++)
      {
       if(i==0)
           dp[i][j]=j;
       else if(j==0)
           dp[i][j]=i;
       else if(str1[i-1]==str2[j-1])
           dp[i][j]=dp[i-1][j-1];
       else
           dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
      }
     }
     return dp[m][n];
    }
    
    int minDistance(string word1, string word2) 
    {
     int m=word1.length();
     int n=word2.length();
     if(m==0)
         return n;
     if(n==0)
         return m;
     return ed(word1,word2,m,n);
    }
};

/*
https://practice.geeksforgeeks.org/problems/edit-distance/0
https://www.hackerrank.com/contests/cse-830-homework-3/challenges/edit-distance/submissions/
https://www.spoj.com/problems/EDIST/
https://codeforces.com/problemset/problem/531/G
https://www.codechef.com/MARCH16/problems/SEATSTR2
https://www.codechef.com/OCT14/problems/SEATSR
https://www.codechef.com/problems/IOPC17E
https://codeforces.com/problemset/problem/530/G
*/

/*
Insert: Recur for m and n-1
Remove: Recur for m-1 and n
Replace: Recur for m-1 and n-1
*/
