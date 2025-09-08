public class Solution {
    public int EvalRPN(string[] tokens) {
        
        int n = tokens.Length;
        Stack<int> st = new Stack<int>();

        for(int i=0;i<tokens.Length;i++){
            if(tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-"){
                int a = Convert.ToInt32(st.Pop());
                int b = Convert.ToInt32(st.Pop());
                if(tokens[i] == "/") a = b / a;
                else if(tokens[i] == "*") a = a * b;
                else if(tokens[i] == "+") a = a + b;
                else a = (b - a);
                st.Push(a); 
            }
            else{
                int t = Convert.ToInt32(tokens[i]);
                st.Push(t); 
            }
        }

        return st.Peek();
        
    }
}