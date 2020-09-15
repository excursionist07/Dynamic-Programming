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


ll lislength(ll a[],ll n)
{
	ll k[n];
	f(n)
	{
		k[i]=1;
	}
	for(ll j=1;j<n;j++)
	{
		for(ll i=0;i<j;i++)
		{
			if(a[i]<a[j])
				k[j]=max(k[j],k[i]+1);
		}
	}
	return *max_element(k,k+n);
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
	{
		cin>>a[i];
	}
	cout<<lislength(a,n)<<endl;
    }
	return 0;
}

// n*log(n)

class Solution {
public:
    int bs(vector<int>&ans,int lo,int hi,int x) // lower_bound using binary search
    {
     while(lo<=hi)
     {
      int mid=(lo+hi)/2;
      if(ans[mid]==x)
          hi=mid-1;
      else if(ans[mid]>x)
          hi=mid-1;
      else
          lo=mid+1;
     }
     return max(0,lo);
    }
    int lengthOfLIS(vector<int>& nums)
    {
     vector<int>ans;
     for(int i=0;i<nums.size();i++)
     {
      //int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
	     // OR
      int idx=bs(ans,0,ans.size()-1,nums[i]);
      if(idx==ans.size())
         ans.push_back(nums[i]);
      else
          ans[idx]=nums[i];
     }
     return ans.size();
    }
};

/*
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem
https://www.codechef.com/problems/PEC005
https://www.codechef.com/problems/LISA
https://www.hackerearth.com/problem/algorithm/longest-increasing-subsequence-2/
https://codeforces.com/problemset/problem/1017/C
*/
