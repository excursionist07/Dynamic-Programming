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

void minncoins(ll coins[],ll total,ll n)
{
 ll k[n][total+1];
 for(ll i=0;i<total+1;i++)
 {
  if(i%coins[0]==0)
    k[0][i]=i/coins[0];
  else
    k[0][i]=HRX;
 }
 for(ll i=1;i<n;i++)
 {
  for(ll j=0;j<total+1;j++)
  {
    if(j==0)
      k[i][j]=0;
    else if(j>=coins[i])
     k[i][j]=min(k[i-1][j],1+k[i][j-coins[i]]);
    else
     k[i][j]=k[i-1][j];

  }
 }
 if(k[n-1][total]==HRX)
   cout<<"-1"<<endl;
 else
   cout<<k[n-1][total]<<endl;
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
  ll coins[n];
  f(n)
  {
    cin>>coins[i];
  }
  sort(coins,coins+n);
  ll total;
  cin>>total;
  minncoins(coins,total,n);
 }
 return 0;
}

/*
https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0/?track=md-dp&batchId=144
https://www.spoj.com/problems/CODEM5/
https://www.hackerrank.com/contests/justcode/challenges/minimum-number-of-coins-for-possible-sum
https://www.spoj.com/problems/COINS/cstart=280
https://www.codechef.com/CYOC2018/problems/LNOC
https://codeforces.com/problemset/problem/1037/A
https://codeforces.com/problemset/problem/160/A
https://codeforces.com/problemset/problem/725/E
*/

/*
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

void minncoins(ll coins[],ll total,ll n)
{
 ll k[n+1][total+1];
 for(ll i=0;i<=n;i++)
  k[i][0]=0;
 for(ll i=1;i<=total;i++)
  k[0][i]=HRX;
 for(ll i=1;i<=n;i++)
 {
  for(ll j=1;j<=total;j++)
  {
    
    if(j>=coins[i-1])
     k[i][j]=min(k[i-1][j],1+k[i][j-coins[i-1]]);
    else
     k[i][j]=k[i-1][j];

  }
 }
 if(k[n][total]==HRX)
   cout<<"-1"<<endl;
 else
   cout<<k[n][total]<<endl;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n,total;
  cin>>total>>n;
  ll coins[n];
  f(n)
  {
    cin>>coins[i];
  }
 // sort(coins,coins+n);
 
  minncoins(coins,total,n);
 }
 return 0;
}
*/
