#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll INF=1e9+7;

ll maxarea(ll a[],ll n)
{
 ll maxx=0,i=0,tp;
 stack<ll>stk;
 while(i<n)
 {
  if(stk.empty() || a[i]>=a[stk.top()])
    stk.push(i),i++;
  else
  {
   tp=stk.top();
   stk.pop();
   if(stk.empty())
    maxx=max(maxx,a[tp]*i);
   else
    maxx=max(maxx,a[tp]*(i-stk.top()-1));
  }
 }
 while(stk.empty())
 {
  tp=stk.top();
  stk.pop();
  if(stk.empty())
    maxx=max(maxx,a[tp]*i);
  else
    maxx=max(maxx,a[tp]*(i-stk.top()-1));
 }
 return maxx;


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
  f(n)
   cin>>a[i];
  cout<<maxarea(a,n)<<"\n";
 }
 return 0;
}
