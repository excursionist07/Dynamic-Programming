#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof dp)
#define INF 1000000007
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;


ll matrixmultiplication(ll a[],ll n)
{
    ll dp[n][n];
    ll j,len,i,k,q;
    for(i=1;i<n;i++)
        dp[i][i]=0;
    for(len=2;len<n;len++)
    {
        for(i=1;i<n-len+1;i++)
        {
             j=i+len-1;
            dp[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<dp[i][j])
                    dp[i][j]=q;
            }
        }
    }
    return dp[1][n-1];
}
int main()
{
  ll n;
  cin>>n;
  ll a[n];
  f(n)
  {
      cin>>a[i];
  }
  cout<<matrixmultiplication(a,n)<<endl;
  return 0;

}

/*
https://www.codechef.com/problems/MIXTURES
https://www.spoj.com/problems/MIXTURES/
*.
