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
typedef  long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

ll up,down;
ll maxx_sum;
ll minn,start,endd;


void kadane(ll temp[],ll m)
{
 ll maxx=0,s=0;
 minn=INT_MIN,start=0,endd=0;
 for(ll i=0;i<m;i++)
 {
  maxx=maxx+temp[i];
  if(maxx<0)
  {
   maxx=0;
   s=i+1;
  }
  if(maxx>minn)
  {
   minn=max(maxx,minn);
   start=s;
   endd=i;
  }
 }

}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll m,n;
  cin>>m>>n;
  ll a[m][n];
  f(m)
  {
   r(n)
   {
    cin>>a[i][j];
   }
  }
  ll temp[m],left,right;
  maxx_sum=INT_MIN;
  for(ll i=0;i<n;i++)
  {
   mem(temp,0);
   for(ll j=i;j<n;j++)
   {
    for(ll k=0;k<m;k++)
        temp[k]+=a[k][j];
    kadane(temp,m);
    if(minn>maxx_sum)
   {
    maxx_sum=minn;
    up=start;
    down=endd;
    left=i;
    right=j;
   }
   }
  }
  cout<<maxx_sum<<endl;
  cout<<left<<" "<<right<<" "<<up<<" "<<down<<endl;

 }
 return 0;


}
