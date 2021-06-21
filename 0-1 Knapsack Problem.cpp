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

// subset sum problem

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

bool subsetsum(ll a[],ll n,ll sum)
{
    ll subset[n+1][sum+1];
    for(ll i=0;i<=n;i++)
        subset[i][0]=true;
    for(ll i=1;i<=sum;i++)
        subset[0][i]=false;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            if(j<a[i-1])
                subset[i][j]=subset[i-1][j];
            else
                subset[i][j]=subset[i-1][j] || subset[i-1][j-a[i-1]];
        }
    }
    return subset[n][sum];
}
int main()
{
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
        ll sum;
        cin>>sum;
        if(subsetsum(a,n,sum))
            cout<<"Truuu"<<endl;
        else
            cout<<"Faalse"<<endl;

    }
    return 0;

}


// Minimum sum partition

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

void msp(ll a[],ll n,ll sum)
{
 bool dp[n+1][sum+1];
 for(ll i=0;i<n+1;i++)
    dp[i][0]=1;
 for(ll i=1;i<sum+1;i++)
    dp[0][i]=0;
 for(ll i=1;i<n+1;i++)
 {
  for(ll j=1;j<sum+1;j++)
  {
    if(j>=a[i-1])
     dp[i][j]=(dp[i-1][j])|(dp[i-1][j-a[i-1]]);
    else
     dp[i][j]=dp[i-1][j];
  }
 }
 ll diff=INT_MAX;
 for(ll i=sum/2;i>=0;i--)
 {
  if(dp[n][i])
  {
    diff=sum-2*i;
    break;
  }
 }
 cout<<diff<<endl;

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
  ll sum=0;
  f(n)
  {
    cin>>a[i];
    sum+=a[i];
  }

  msp(a,n,sum);
 }
 return 0;
}

// Rodcuttingproblem

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

ll rodcutting(ll L[],ll cost[],ll n,ll len)// Same as unbounded knapsack
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



// rod cutting with exact weight to minimize the cost

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
