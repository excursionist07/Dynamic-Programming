/*
1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
     int n=heights.size();
     if(n==0)
         return 0;
     if(n==1)
         return heights[0];
     stack<int>stk;
     int i=0,maxx=0,tp;
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
