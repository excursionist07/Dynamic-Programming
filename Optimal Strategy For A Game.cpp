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

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  ll a[n];
  rep(i,0,n)
   cin>>a[i];
  ll dp[n][n];
  rep(i,0,n)
   dp[i][i]=a[i];
  rep(i,0,n-1)
   dp[i][i+1]=max(a[i],a[i+1]);
  for(ll len=3;len<=n;len++)
  {
    for(ll i=0;i<n-len+1;i++)
    {
     ll j=i+len-1;
     dp[i][j]=max(a[i]+min(dp[i+1][j-1],dp[i+2][j]),a[j]+min(dp[i][j-2],dp[i+1][j-1]));
    }
  }
  cout<<dp[0][n-1]<<"\n";
  
 }
 return 0;
 
}

// dp(i, j) represents the maximum value the user can collect from i'th coin to j'th coin.

