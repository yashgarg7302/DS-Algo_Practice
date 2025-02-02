class Solution {
public:
    int minAddToMakeValid(string s) {
         stack<char> stack;
        
        for(char st : s){
            if(st=='(')
                stack.push(st);
            else{
                if(!stack.empty() && stack.top()=='(')
                    stack.pop();
                else
                    stack.push(st);
            }
        }
        return stack.size();
    }
};