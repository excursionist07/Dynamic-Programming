#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll INF=1e9+7;

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
   cin>>a[i];
  ll dp[n];
  if(n==0)
  {
   cout<<"0"<<"\n";
   continue;
  }
  if(n==1)
  {
   cout<<a[0]<<"\n";
   continue;
  }
  if(n==2)
  {
   cout<<max(a[0],a[1])<<"\n";
   continue;
  }
  dp[0]=a[0];
  dp[1]=max(a[0],a[1]);
  for(ll i=2;i<n;i++)
    dp[i]=max(dp[i-1],a[i]+dp[i-2]);
  cout<<dp[n-1]<<"\n";
 }
 return 0;


}
