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
    ll a[n],lis[n],lds[n];
    rep(i,0,n)
    {
     cin>>a[i];
     lis[i]=1;
     lds[i]=1;
    }
    for(ll j=1;j<n;j++)
    {
     for(ll i=0;i<j;i++)
     {
      if(a[j]>a[i])
       lis[j]=max(lis[j],1+lis[i]);
     }
    }
    for(ll j=n-2;j>=0;j--)
    {
     for(ll i=n-1;i>j;i--)
     {
      if(a[j]>a[i])
       lds[j]=max(lds[j],1+lds[i]);
     }
    }
    ll maxx=-1;
    rep(i,0,n)
     maxx=max(maxx,lis[i]+lds[i]-1);
    cout<<maxx<<"\n";
     
    
  }
  return 0;
 }
