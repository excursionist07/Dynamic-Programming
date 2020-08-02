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


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n],b[n],c[n];
  f(n)
  {
   cin>>a[i];
   b[i]=1;
   c[i]=1;
  }

  for(ll j=1;j<n;j++)
  {
    for(ll i=0;i<j;i++)
    {
     if(a[j]>a[i])
       b[j]=max(b[i]+1,b[j]);
    }
  }


  for(ll j=n-2;j>=0;j--)
  {
    for(ll i=n-1;i>j;i--)
    {
     if(a[j]>a[i])
      c[j]=max(c[j],c[i]+1);
    }
  }
  ll maxx=-1;
  f(n)
  {
    if(c[i]+b[i]-1>maxx)
      maxx=c[i]+b[i]-1;
  }
  cout<<maxx<<endl;
 }

 return 0;
}
