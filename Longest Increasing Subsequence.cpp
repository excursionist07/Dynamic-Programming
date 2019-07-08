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


ll lislength(ll a[],ll n)
{
	ll k[n];
	f(n)
	{
		k[i]=1;
	}
	for(ll j=1;j<n;j++)
	{
		for(ll i=0;i<j;i++)
		{
			if(a[i]<a[j])
				k[j]=max(k[j],k[i]+1);
		}
	}
	return *max_element(k,k+n);
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
	ll a[n];
	f(n)
	{
		cin>>a[i];
	}
	cout<<lislength(a,n)<<endl;
    }
	return 0;
}
