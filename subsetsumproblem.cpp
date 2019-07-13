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

bool subsetsum(ll a[],ll n,ll sum)
{
    ll subset[n+1][sum+1];
    for(ll i=0;i<=n;i++)
        subset[i][0]=true;
    for(ll i=1;i<=sum;i++)
        subset[0][i]=false;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            if(j<a[i-1])
                subset[i][j]=subset[i-1][j];
            else
                subset[i][j]=subset[i-1][j] || subset[i-1][j-a[i-1]];
        }
    }
    return subset[n][sum];
}
int main()
{
    ll t;
    cin>>t;
    f(t)
    {
        ll n;
        cin>>n;
        ll a[n];
        f(n)
        {
        cin>>a[i];
        }
        ll sum;
        cin>>sum;
        if(subsetsum(a,n,sum))
            cout<<"Truuu"<<endl;
        else
            cout<<"Faalse"<<endl;

    }
    return 0;

}

/*
https://www.hackerrank.com/challenges/subset-sum/problem
https://www.codechef.com/problems/TF01
https://www.codechef.com/problems/REN2013D
https://www.hackerearth.com/problem/algorithm/subset-sum-2/
https://www.hackerearth.com/problem/algorithm/print-subset-sum-to-k/
*/
