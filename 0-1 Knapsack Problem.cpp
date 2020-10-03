// 0-1 Knapsack Problem


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

/*
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
https://www.hackerearth.com/problem/algorithm/lks-large-knapsack/
https://www.hackerearth.com/problem/algorithm/knapsack-1/
https://www.codechef.com/problems/KNPSK
http://codeforces.com/problemset/gymProblem/101064/L
https://codeforces.com/problemset/problem/19/B
*/


// unbounded_knapsack


// same as rod cutting

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

void unbounded_kanpsack(ll wt[],ll val[],ll n,ll total)
{
  ll k[n+1][total+1];
  f(n+1)
  {
    r(total+1)
    {
      if(i==0 || j==0)
        k[i][j]=0;
      else if(j>=wt[i-1])
        k[i][j]=max(k[i-1][j],val[i-1]+k[i][j-wt[i-1]]);
      else
        k[i][j]=k[i-1][j];
    }
  }
  cout<<k[n][total]<<endl;
}
int main()
{
  hs;
  ll n;
  cin>>n;
  ll wt[n],val[n];
  f(n)
  {
    cin>>wt[i]>>val[i];
  }
  ll total;
  cin>>total;
  unbounded_kanpsack(wt,val,n,total);
  return 0;
}

/*
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
*/
