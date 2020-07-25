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

 /* int lcs(string s1,string s2,int m,int n) ??Recursive
    {
     if(m==0 || n==0)
         return 0;
     else if(s1[m-1]==s2[n-1])
         return 1+lcs(s1,s2,m-1,n-1);
     else
         return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
         
    }*/
    

void lcs(string s1,string s2,ll m,ll n)
{
	ll k[m+1][n+1];
	f(m+1)
	{
		r(n+1)
		{
			if(i==0 || j==0)
				k[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				k[i][j]=k[i-1][j-1]+1;
			else
				k[i][j]=max(k[i-1][j],k[i][j-1]);
		}
	}

	
    if(k[m][n]!=0)
    {
    ll index=k[m][n];
    char ch[index];
    ll i=m,j=n;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {

         ch[index-1]=s1[i-1];
         i--;
         j--;
         index--;

        }
        else if(k[i-1][j]>k[i][j-1])
           i--;
        else
           j--;
    }


    f(k[m][n])
      cout<<ch[i];
    cout<<" "<<k[m][n]<<endl;
    }

    else
    {
        cout<<"no common thing"<<endl;
    }


}

int main()
{
	hs;
	ll t;
	cin>>t;
	while(t--)
	{
	  string s1,s2;
	  cin>>s1>>s2;
	  ll a=s1.length();
	  ll b=s2.length();
	  lcs(s1,s2,a,b);

	}
	return 0;
}

/*
https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
https://www.codechef.com/CORD2019/problems/CR194
https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem
https://www.hackerrank.com/challenges/tutzki-and-lcs/problem
https://www.codechef.com/problems/CHEFKLCS
https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
https://codeforces.com/problemset/problem/346/B
http://codeforces.com/problemset/gymProblem/101262/B
*/
*/
