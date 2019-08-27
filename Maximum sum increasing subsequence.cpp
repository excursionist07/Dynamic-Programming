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
    b[i]=a[i];
    c[i]=i;
  }
  for(ll j=1;j<n;j++)
  {
    for(ll i=0;i<j;i++)
    {
     if(a[j]>a[i])
     {
      b[j]=max(b[j],a[j]+b[i]);
      if(b[j]==a[j]+b[i])
        c[j]=i;
     }
    }
  }

  ll maxx=-1,index;
  f(n)
  {
   if(b[i]>maxx)
   {
    maxx=b[i];
    index=i;
   }
  }
  cout<<maxx<<endl;

  ll sum=0;
  while(sum!=maxx)
  {
    cout<<a[index]<<" ";
    sum=sum+a[index];
    index=c[index];
  }
 }
 return 0;
}

/*
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
https://www.codechef.com/problems/LISA
https://www.codechef.com/problems/SEAINCR
https://www.codechef.com/problems/MMSUM
*/
