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

const ll N=76;
ll dp[N];
void keyboard()
{

 f(7)
  dp[i]=i;
 for(ll i=7;i<=N;i++)
 {
  dp[i]=max(2*dp[i-3],(max(3*dp[i-4],4*dp[i-5])));
 }

}
int main()
{
 hs;
 ll t;
 cin>>t;
 keyboard();
 f(t)
 {
  ll n;
  cin>>n;
  if(n>75)
    cout<<"-1"<<endl;
  else
    cout<<dp[n]<<endl;
 }
 return 0;
}
