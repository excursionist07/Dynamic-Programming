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
 ll up,down,start,endd;
 
 ll kadane(ll temp[],ll n)
 {
  ll maxx=-ESP,s=0,idx=0,cur=0;
  start=0;
  endd=0;
  while(idx<n)
  {
   cur+=temp[idx];
   if(cur>maxx)
   {
    maxx=cur;
    start=s;
    endd=idx;
   }
   if(cur<0)
   {
    cur=0;
    s=idx+1;
   }
   idx++;
  }
  return maxx;
 }
 
 int main()
 {
  hs;
  ll t;
  cin>>t;
  while(t--)
  {
   ll m,n;
   cin>>m>>n;
   ll a[m][n];
   rep(i,0,m)
   {
    rep(j,0,n)
    {
     cin>>a[i][j];
    }
   }
   ll maxx=-ESP;
   ll temp[m],left,right;
   for(ll i=0;i<n;i++)
   {
    mem(temp,0);
    for(ll j=i;j<n;j++)
    {
     for(ll k=0;k<m;k++)
       temp[k]+=a[k][j];
     ll zz=kadane(temp,m);
     if(zz>maxx)
     {
      maxx=zz;
      left=i;
      right=j;
      up=start;
      down=endd;
     }
    }
   }
   cout<<maxx<<"\n";
   //cout<<left<<" "<<right<<" "<<up<<" "<<down<<"\n";
   
  }
  return 0;
 }
