// Longest Common Subsequence

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

//  LCS of three strings

#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/
ll doit(string s1,string s2,string s3,ll n1,ll n2,ll n3)
{
 ll dp[1+n1][1+n2][1+n3];
 rep(i,0,1+n1)
 {
  rep(j,0,1+n2)
  {
    rep(k,0,1+n3)
    {
     if(i==0 || j==0 || k==0)
      dp[i][j][k]=0;
     else if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
      dp[i][j][k]=1+dp[i-1][j-1][k-1];
     else
      dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
    }
  }
 }
 return dp[n1][n2][n3];
}
int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n1,n2,n3;
  cin>>n1>>n2>>n3;
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  cout<<doit(s1,s2,s3,n1,n2,n3)<<"\n";
 }
 return 0;
}

// 516. Longest Palindromic Subsequence

class Solution {
public:

    int lps(string s1,string s2,int n) // Just Reverse the string and take LCS(longest common subsequence) with it
    {
     int dp[n+1][n+1];
     for(int i=0;i<=n;i++)
     {
      for(int j=0;j<=n;j++)
      {
       if(i==0 || j==0)
           dp[i][j]=0;
       else if(s1[i-1]==s2[j-1])
           dp[i][j]=1+dp[i-1][j-1];
       else
           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
     }
     return dp[n][n];
    }
    int longestPalindromeSubseq(string s)
    {
     int n=s.length();
     string s2=s;
     reverse(s2.begin(),s2.end());
     return lps(s,s2,n);
    }
};

// Shortest Common Supersequence

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


// longestcommonsubstring

#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 */
 
 ll lcs(string str1,string str2,ll m,ll n)
 {
  ll dp[m+1][n+1];
  ll maxx=0,row,col;
  for(ll i=0;i<=m;i++)
  {
   for(ll j=0;j<=n;j++)
   {
     if(i==0 || j==0)
      dp[i][j]=0;
     else if(str1[i-1]==str2[j-1])
     {
      dp[i][j]=1+dp[i-1][j-1];
      if(dp[i][j]>maxx)
      {
       maxx=dp[i][j];
       row=i;
       col=j;
      }
     }
     else
      dp[i][j]=0;
   }
  }
  string ans="";
  while(dp[row][col]!=0)
  {
    ans+=str1[row-1];
    row--;
    col--;
   
  }
  reverse(ans.begin(),ans.end());
  cout<<ans;
  return maxx;
 }
 
 int main()
 {
  hs;
  ll t;
  cin>>t;
  while(t--)
  {
   ll m,n;
   cin>>m>>n;
   string str1,str2;
   cin>>str1>>str2;
   cout<<lcs(str1,str2,m,n)<<"\n";
   
  }
  return 0;
 }

// Edit Distance

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
