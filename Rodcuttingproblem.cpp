#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof dp)
#define INF 1000000007
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;

ll rodcutting(ll L[],ll cost[],ll n,ll len)
{
  ll k[n+1][len+1];
  for(ll i=0;i<=n;i++)
  {
  	for(ll j=0;j<=len;j++)
  	{
  		if(i==0 || j==0)
  			k[i][j]=0;
  		else if(j>=L[i-1])
  			k[i][j]=max(k[i-1][j],cost[i-1]+k[i][j-L[i-1]]);
  		else
  			k[i][j]=k[i-1][j];
  	}
  }
  return k[n][len];
}

int main()
{
    hs;
    ll n;
  	cin>>n;
  	ll L[n],cost[n];
  	f(n)
  	{
  		cin>>L[i];
  	}
  	f(n)
  	{
  		cin>>cost[i];
  	}
  	ll len;
  	cin>>len;
  	cout<<rodcutting(L,cost,n,len)<<endl;

  return 0;
}
