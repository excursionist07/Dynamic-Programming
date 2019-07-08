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

ll knapsack(ll wt[],ll val[],ll n,ll W)
{
	ll k[n+1][W+1];
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=W;j++)
		{
			if(i==0 || j==0)
			    k[i][j]=0;
			else if(wt[i-1]<=j)
				k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
			else
				k[i][j]=k[i-1][j];
		}
	}
	return k[n][W];
}
int main()
{
  hs;
  ll n;
  cin>>n;
  ll wt[n];
  ll val[n];
  f(n)
  {
  	cin>>wt[i];
  }
  f(n)
  {
  	cin>>val[i];
  }
  ll W;
  cin>>W;
  cout<<knapsack(wt,val,n,W)<<endl;
  return 0;
}
