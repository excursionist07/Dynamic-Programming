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

void uglyno(ll n)
{
 ll ugly[n];
 ll aa=2;
 ll bb=3;
 ll cc=5;
 ll i2=0;
 ll i3=0;
 ll i5=0;
 ll nun=1;
 ugly[0]=1;
 for(ll i=1;i<n;i++)
 {
  nun=min(aa,min(bb,cc));
  ugly[i]=nun;
  if(nun==aa)
  {
    i2=i2+1;
    aa=(ugly[i2])*2;
  }
  if(nun==bb)
  {
    i3=i3+1;
    bb=(ugly[i3])*3;
  }
  if(nun==cc)
  {
    i5=i5+1;
    cc=(ugly[i5])*5;
  }
 }
 cout<<nun<<endl;
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
  uglyno(n);
 }
 return 0;

}
