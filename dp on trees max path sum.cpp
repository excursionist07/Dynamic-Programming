#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll INF=1e9+7;

const ll N=1e5+7;
ll a[N],dp[N];
vector<ll>adj[N];
ll n;

void dfs(ll u,ll par)
{
 dp[u]=a[u-1];
 ll mx=0;
 for(ll child:adj[u])
 {
  if(child==par)continue;
  dfs(child,u);
  mx=max(mx,dp[child]);
 }
 dp[u]+=mx;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>n;
  f(n-1)
  {
   ll x,y;
   cin>>x>>y;
   adj[x].pb(y);
   adj[y].pb(x);
  }
  f(n)
   cin>>a[i];
  dfs(1,0);
  cout<<dp[1]<<"\n";
 }
 return 0;
}
