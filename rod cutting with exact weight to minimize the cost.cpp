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

ll minimize_cost(ll w,ll n,ll wt2[],ll val[])
{
	ll k[n+1][w+1];
	f(w+1)
	  k[0][i]=INF;
	for(ll i=1;i<n+1;i++)
		k[i][0]=0;
	for(ll i=1;i<n+1;i++)
	{
		for(ll j=1;j<w+1;j++)
		{
			if(wt2[i-1]<=j)
				k[i][j]=min(k[i-1][j],val[i-1]+k[i][j-wt2[i-1]]);
			else
				k[i][j]=k[i-1][j];
		}
	}
return k[n][w];
}


int main()
{
	hs;
	ll n,w;
	cin>>n>>w;
	ll wt1[n],wt2[n],val[n];
	f(n)
	{
		cin>>wt2[i]>>val[i];

	}

	cout<<minimize_cost(w,n,wt2,val)<<endl;
	return 0;



}
