const int N=1e3+7;
    int dp[N][N];

class Solution {
public:
    
    
 int histoarea(vector<int>vec)
{
 int n=vec.size();
 int i=0,tp,maxx=0;
 stack<int>stk;
 while(i<n)
 {
   if(stk.empty() || vec[i]>=vec[stk.top()])
    stk.push(i),i++;
   else
   {
     tp=stk.top();
     stk.pop();
     if(stk.empty())
      maxx=max(maxx,vec[tp]*i);
     else
      maxx=max(maxx,vec[tp]*(i-stk.top()-1));
   }
 }
 while(!stk.empty())
 {
     tp=stk.top();
     stk.pop();
     if(stk.empty())
      maxx=max(maxx,vec[tp]*i);
     else
      maxx=max(maxx,vec[tp]*(i-stk.top()-1));
 }
 return maxx;
}
    int maximalRectangle(vector<vector<char>>& matrix)
    {
     int m=matrix.size();
     if(m==0)return 0;
     int n=matrix[0].size();
     for(int i=0;i<n;i++)
         dp[0][i]=matrix[0][i]-'0';
     for(int i=1;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(matrix[i][j]=='1')
           dp[i][j]=1+dp[i-1][j];
       else
           dp[i][j]=0;
      }
     }
     int maxx=0;
     for(int i=0;i<m;i++)
 {
  vector<int>vec;
  for(int j=0;j<n;j++)
  {
    vec.push_back(dp[i][j]);
  }
  maxx=max(maxx,histoarea(vec));
 }
 return maxx;
     
    }
};
