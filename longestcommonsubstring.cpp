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
vector<pair<ll,pair<ll,ll>>>vec;

void lcsubstring(string s1,string s2,ll m,ll n)
{
 ll k[m+1][n+1];
 ll maxx=0;
 f(m+1)
 {
  r(n+1)
  {
    if(i==0 || j==0)
      k[i][j]=0;
    else if(s1[i-1]==s2[j-1])
    {
     k[i][j]=k[i-1][j-1]+1;
     maxx=max(maxx,k[i][j]);
     vec.pb(m_p(maxx,m_p(i,j)));
    }

    else
      k[i][j]=0;
  }
 }
 sort(vec.begin(),vec.end());
 ll xx=vec[vec.size()-1].second.first;
 ll yy=vec[vec.size()-1].second.second;
 ll ans=vec[vec.size()-1].first;
 //cout<<ans<<" "<<xx<<" "<<yy;
 ll index=ans;
 char ch[index];

 while(k[xx][yy]!=0)
 {
  if(s1[xx-1]==s2[yy-1])
  {
    ch[index-1]=s1[xx-1];
    xx--;
    yy--;
    index--;

  }
 }
 cout<<ans<<endl;
 for(ll i=0;i<ans;i++)
    cout<<ch[i];
 cout<<"\n";


}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string s1,s2;
  cin>>s1>>s2;
  ll m=s1.length();
  ll n=s2.length();
  lcsubstring(s1,s2,m,n);
 }
 return 0;
}
