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

void minimize_cost(ll len[],ll cost[],ll n,ll total)
{
  ll k[n+1][total+1];
   for(ll i=0;i<n+1;i++)
    k[i][0]=0;
  for(ll i=1;i<total+1;i++)
    k[0][i]=HRX;
 
  for(ll i=1;i<n+1;i++)
  {
    for(ll j=1;j<total+1;j++)
    {
      if(j>=len[i-1])
        k[i][j]=min(k[i-1][j],cost[i-1]+k[i][j-len[i-1]]);
      else
        k[i][j]=k[i-1][j];
    }
  }
  if(k[n][total]!=HRX)
    cout<<k[n][total]<<endl;
  else
     cout<<"-1"<<"\n";
}

int main()
{
  hs;
  ll t;
  cin>>t;
  f(t)
  {
    ll n;
    cin>>n;
    ll len[n],cost[n];
    f(n)
    {
      cin>>len[i]>>cost[i];
    }
    ll total;
    cin>>total;
    minimize_cost(len,cost,n,total);
  }
  return 0;
}



}
