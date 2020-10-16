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

/*
https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
https://www.hackerrank.com/challenges/subset-sum/problem
https://www.codechef.com/problems/TF01
https://www.codechef.com/problems/REN2013D
https://www.hackerearth.com/problem/algorithm/subset-sum-2/
https://www.hackerearth.com/problem/algorithm/print-subset-sum-to-k/
*/

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
