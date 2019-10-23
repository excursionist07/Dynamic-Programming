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
