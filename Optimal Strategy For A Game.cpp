#include<bits/stdc++.h>
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

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n];
  f(n)
  {
   cin>>a[i];
  }
  ll dp[n][n];
  f(n)
  {
   dp[i][i]=a[i];
  }
  for(ll i=0;i<n-1;i++)
  {
    dp[i][i+1]=max(a[i],a[i+1]);
  }
  for(ll k=3;k<=n;k++)
  {
   for(ll i=0;i<n-k+1;i++)
   {
    ll j=i+k-1;
    dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
   }
  }
  cout<<dp[0][n-1]<<endl;

 }
 return 0;
}
