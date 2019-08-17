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

void maxxfloors(ll e,ll f)
{
 ll k[e+1][f+1];
 ll res;
 for(ll i=0;i<=f;i++)
    k[0][i]=0;
 for(ll i=1;i<=e;i++)
 {
  k[i][0]=0;
  k[i][1]=1;
 }
 for(ll i=1;i<=f;i++)
    k[1][i]=i;
 for(ll i=2;i<=e;i++)
 {
  for(ll j=2;j<=f;j++)
  {
   k[i][j]=HRX;
   for(ll x=1;x<=j;x++)
   {
    res=1+max(k[i-1][x-1],k[i][j-x]);
    if(res<k[i][j])
        k[i][j]=res;
   }
  }
 }
 cout<<k[e][f]<<endl;

}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll eggs,floors;
  cin>>eggs>>floors;
  maxxfloors(eggs,floors);
 }
 return 0;
}
