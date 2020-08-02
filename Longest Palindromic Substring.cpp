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

void palindromic(string s)
{
  ll n=s.length();
  bool vis[n][n];
  mem(vis,0);
  for(ll i=0;i<n;i++)
    vis[i][i]=1;
  ll maxlength=1;
  ll start=1;
  for(ll i=0;i<n-1;i++)
  {
   if(s[i]==s[i+1])
   {
    vis[i][i+1]=1;
    maxlength=2;
    start=i;
   }
  }
  for(ll k=3;k<=n;k++)
  {
   for(ll i=0;i<n-k+1;i++)
   {
    ll j=i+k-1; //Get the ending index of substring starting index i and length k 
           
    if(vis[i+1][j-1] && s[i]==s[j])
    {
      vis[i][j]=1;
      if(k>maxlength)
      {
       maxlength=k;
       start=i;
      }
    }
   }
  }
  ll low=start;
  ll high=start+maxlength-1;
  cout<<maxlength<<endl;
  for(ll i=start;i<=high;i++)
  {
    cout<<s[i];
  }
  cout<<"\n";

}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string s;
  cin>>s;
  palindromic(s);
 }
 return 0;
}

/*
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
https://www.spoj.com/problems/LPS/
https://www.spoj.com/AU1/problems/LPALIN/
https://www.spoj.com/problems/PALIM/
https://www.hackerrank.com/contests/security-challenge/challenges/largest-palindromic-substring
https://www.hackerrank.com/contests/codejam/challenges/longest-palindrome
https://www.hackerrank.com/contests/daiict-ipc-4/challenges/counting-palindromic-substring
https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/palindromic-sub-string-length/
https://www.hackerearth.com/problem/golf/mrwatson-and-super-logarithms/
https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/practice-problems/algorithm/longest-palindromic-string/
https://codeforces.com/problemset/problem/202/A
https://codeforces.com/problemset/problem/981/A
https://www.codechef.com/ACM15AMR/problems/AMLPALIN
https://www.codechef.com/MARCH16/problems/STRPALIN
*/
