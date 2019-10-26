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



void boxstacking(ll n,ll len[],ll wid[],ll hei[])
{
 ll a[3*n][4];
 ll p=0;
 for(ll i=0;i<n;i++)
 {
  a[p][0]=len[i]*wid[i];
  a[p][1]=len[i];
  a[p][2]=wid[i];
  a[p][3]=hei[i];
  p++;
  a[p][0]=len[i]*hei[i];
  a[p][1]=len[i];
  a[p][2]=hei[i];
  a[p][3]=wid[i];
  p++;
  a[p][0]=hei[i]*wid[i];
  a[p][1]=hei[i];
  a[p][2]=wid[i];
  a[p][3]=len[i];
  p++;

 }
 for(ll j=1;j<p;j++)
 {
  for(ll i=0;i<j;i++)
  {
    if(a[j][0]>a[i][0])
    {
     swap(a[j][0],a[i][0]);
     swap(a[j][1],a[i][1]);
     swap(a[j][2],a[i][2]);
     swap(a[j][3],a[i][3]);

    }
  }
 }
 ll res[p];
 for(ll i=0;i<p;i++)
    res[i]=a[i][3];
 ll maxx=res[0];
 for(ll j=1;j<p;j++)
 {
  for(ll i=0;i<j;i++)
  {
   if((a[i][1]>a[j][1] && a[i][2]>a[j][2]) || (a[i][1]>a[j][2] && a[i][2]>a[j][1]))
     res[j]=max(res[j],a[j][3]+res[i]);
  }
  if(res[j]>maxx)
    maxx=res[j];
 }
 cout<<maxx<<endl;
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
  ll len[n],wid[n],hei[n];
  f(n)
   cin>>len[i]>>wid[i]>>hei[i];
  boxstacking(n,len,wid,hei);
 }
 return 0;
}
