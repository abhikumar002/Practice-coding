public class Solution {
    public bool IsValid(string s) {
        Stack<int> st = new Stack<int>();
        int n = s.Length;
        int i = 0;

        while(i < n){
            if(st.Count != 0 && (s[i] == ')' || s[i] == '}' || s[i] == ']')){
                if(s[i] == ')' && st.Peek() == '(') st.Pop();
                else if(s[i] == '}' && st.Peek() == '{') st.Pop();
                else if(s[i] == ']' && st.Peek() == '[') st.Pop();
                else return false;
            }
            else{
                st.Push(s[i]);
            }
            i++;
        }

        return st.Count == 0;
    }
}