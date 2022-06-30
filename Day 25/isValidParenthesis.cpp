bool isValidParenthesis(string expression)
{
    // Write your code here.
    int n = expression.size();
    stack<char> s;

    for (int i = 0; i < n; i++)
    {
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[')
        {
            s.push(expression[i]);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            else if ((s.top() == '{' && expression[i] == '}') || (s.top() == '(' && expression[i] == ')') || (s.top() == '[' && expression[i] == ']'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(s.size()>0){
       return false;
   }else{
       return true;
   }
}
