//8 Queen Problem - Recursive Backtracking
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define fastio              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F                   first
#define S                   second
#define all(v)              (v).begin(),(v).end()
#define pi					3.14159265359
ll INF=1e18+10;
ll MOD=1000000007;

const int N=8;
int row[N];

bool place(int r,int c)
{
	for(int prev=0;prev<c;prev++)
      if(row[prev]==r || abs(row[prev]-r)==abs(prev-c))
        return false;
  	return true;
}

void backtrack(int c)
{
  	if(c==8)
    {
    	for(int i=0;i<8;i++)
        	cout<<row[i]<<" ";
      	cout<<"\n";
    }
    else
  	for(int r=0;r<8;r++)
      	if(place(r,c)){row[c]=r;backtrack(c+1);}
}

int main()
{
    //freopen("out.txt","w",stdout);
  	backtrack(0);
}
