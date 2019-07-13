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

ll minimum(ll x,ll y,ll z)
{
    return (min(min(x, y), z));
}
ll editdistance(string s1,string s2,ll m,ll n)
{


    ll k[m+1][n+1];

    for(ll i=0;i<m+1;i++)
    {
        for(ll j=0;j<n+1;j++)
        {
            if(i==0)
               k[i][j]=j;
            else if(j==0)
               k[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                k[i][j]=k[i-1][j-1];
            else
                k[i][j]=1+minimum(k[i-1][j],k[i][j-1],k[i-1][j-1]);
        }
    }

        return k[m][n];

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
 cout<<editdistance(s1,s2,s1.length(),s2.length())<<endl;
 }
 return 0;

}

/*
https://www.hackerrank.com/contests/cse-830-homework-3/challenges/edit-distance/submissions/
https://www.spoj.com/problems/EDIST/
https://codeforces.com/problemset/problem/531/G
https://www.codechef.com/MARCH16/problems/SEATSTR2
https://www.codechef.com/OCT14/problems/SEATSR
https://www.codechef.com/problems/IOPC17E
https://codeforces.com/problemset/problem/530/G
*/
