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

ll coinschange(ll coins[],ll n,ll total)
{

	ll k[n][total+1];
	f(n)
	{
	    k[i][0]=1;
	}
	for(ll i=1;i<total+1;i++)
    {
        if(i%coins[0]==0)
            k[0][i]=1;
        else
            k[0][i]=0;
    }

	for(ll i=1;i<n;i++)

	{
		for(ll j=1;j<total+1;j++)
		{
			if(j>=coins[i])
				k[i][j]=k[i-1][j]+k[i][j-coins[i]];
			else
				k[i][j]=k[i-1][j];

		}
	}
	return k[n-1][total];
}

int main()
{
	hs;
	ll n;
	cin>>n;
	ll coins[n];
	f(n)
	{
		cin>>coins[i];
	}
	sort(coins,coins+n);
	ll total;
	cin>>total;
	cout<<coinschange(coins,n,total)<<endl;
	return 0;

}

/*
https://codeforces.com/problemset/problem/433/A
https://www.spoj.com/problems/EINST/
https://www.spoj.com/problems/COINS/
https://www.spoj.com/problems/TPC07/
*/
