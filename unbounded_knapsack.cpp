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


ll unbounded_knapsack(ll val[],ll wt[],ll n,ll w)
{
	ll k[w+1];
	memset(k,0,sizeof(k));
	f(w+1)
	{
      r(n)
      {
      	if(wt[j]<=i)
      		k[i]=max(k[i],val[j]+k[i-wt[j]]);
      }
	}
	return k[w];
}
int main()
{
	ll w,m;
	cin>>w>>m;
	ll wt[m],val[m];
	f(m)
	{
		cin>>wt[i]>>val[i];
	}
	cout<<unbounded_knapsack(val,wt,m,w)<<endl;
	return 0;
}
