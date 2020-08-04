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
