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

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string str;
  cin>>str;
  ll n=str.length();
  ll maxx=0;
  stack<char>stk;
  stk.push(-1);
  f(n)
  {
   if(str[i]=='(')
     stk.push(i);
   else
   {
    stk.pop();
    if(!stk.empty())
        maxx=max(maxx,i-stk.top());
    else
        stk.push(i);//base for next
   }
  }
  cout<<maxx<<"\n";
 }
 return 0;
}
