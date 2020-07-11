#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  ll a[n];
  rep(i,0,n)
   cin>>a[i];
  ll tar;
  cin>>tar;
  ll dp[tar+1];
  dp[0]=1;
  rep(i,1,tar+1)
   dp[i]=0;
  for(ll i=1;i<=tar;i++)
  {
   for(ll j=0;j<n;j++)
   {
    if(i-a[j]>=0)
        dp[i]+=dp[i-a[j]];
   }
  }
  cout<<dp[tar]<<"\n";
 }
 return 0;
}
