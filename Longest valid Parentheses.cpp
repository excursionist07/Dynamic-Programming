class Solution {
public:
    int longestValidParentheses(string s) 
    {
     int n=s.length();
     if(n<=1)
         return 0;
     int maxx=0;
     stack<int>stk;
     stk.push(-1);
     for(int i=0;i<n;i++)
     {
      if(s[i]=='(')
          stk.push(i);
      else
      {
       stk.pop();
       if(!stk.empty())
           maxx=max(maxx,i-stk.top());
       else
           stk.push(i);
      }
     }
     return maxx;
     
     
    }
};
