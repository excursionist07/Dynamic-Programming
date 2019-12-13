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

void MaxProfit(ll price[],ll n,ll k)
{
 ll dp[k+1][n];

 for(ll i=0;i<=k;i++)
 {
  for(ll j=0;j<n;j++)
  {
    if(i==0 || j==0)
      dp[i][j]=0;
    else
    {
    ll res=INT_MIN;
    for(ll p=0;p<j;p++)
      res=max(res,price[j]-price[p]+dp[i-1][p]);
    dp[i][j]=max(dp[i][j-1],res);
    }
  }
 }
 cout<<dp[k][n-1]<<endl;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll k,n;
  cin>>k>>n;
  ll price[n];
  f(n)
   cin>>price[i];
  MaxProfit(price,n,k);
 }
 return 0;
}
