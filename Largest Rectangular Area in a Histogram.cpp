class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
     int n=heights.size();
     if(n==0)return 0;
     stack<int>stk;
     int i=0,tp,maxx=0;
     while(i<n)
     {
      if(stk.empty() || heights[i]>=heights[stk.top()])
          stk.push(i),i++;
      else
      {
        tp=stk.top();
        stk.pop();
        if(stk.empty())
            maxx=max(maxx,heights[tp]*i);
        else
            maxx=max(maxx,heights[tp]*(i-stk.top()-1));
      }
     }
     while(!stk.empty())
     {
      tp=stk.top();
      stk.pop();
      if(stk.empty())
         maxx=max(maxx,heights[tp]*i);
      else
         maxx=max(maxx,heights[tp]*(i-stk.top()-1));
     }
     return maxx;
    }
};
