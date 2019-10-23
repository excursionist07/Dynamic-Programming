#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

void scs(string s1,string s2)
{
 ll m=s1.length();
 ll n=s2.length();
 ll dp[m+1][n+1];
 f(m+1)
 {
  r(n+1)
  {
    if(!i)
     dp[i][j]=j;
    else if(!j)
     dp[i][j]=i;
    else if(s1[i-1]==s2[j-1])
     dp[i][j]=1+dp[i-1][j-1];
    else
     dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
  }
 }
 ll index=dp[m][n];
 char ch[index];
 ll i=m,j=n;
 while(i>0 && j>0)
 {
  if(s1[i-1]==s2[j-1])
  {
   ch[index-1]=s1[i-1];
   index--;
   i--;
   j--;
  }
  else if(dp[i][j-1]>dp[i-1][j])
  {
    ch[index-1]=s1[i-1];
    i--;
    index--;
  }
  else
  {
    ch[index-1]=s2[j-1];
    j--;
    index--;
  }
 }
 while(i>0)
 {
  ch[index-1]=s1[i-1];
  i--;
  index--;
 }
 while(j>0)
 {
  ch[index-1]=s2[j-1];
  j--;
  index--;
 }
 cout<<dp[m][n]<<endl;
 f(dp[m][n])
  cout<<ch[i];
 cout<<"\n";
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string str1,str2;
  cin>>str1>>str2;
  scs(str1,str2);

 }
 return 0;
}
