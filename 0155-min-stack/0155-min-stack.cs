public class MinStack {

    Stack<int> st;
    Stack<int> minst;
    public MinStack() {
        st = new Stack<int>();
        minst = new Stack<int>();
    }
    
    public void Push(int val) {
        st.Push(val);
        if(minst.Count == 0 || val <= minst.Peek()){
            minst.Push(val);
        }
    }
    
    public void Pop() {
        int t = st.Peek();
        st.Pop();
        if(t == minst.Peek()){
            minst.Pop();
        }     
    }
    
    public int Top() {
        return st.Peek();
    }
    
    public int GetMin() {
        return minst.Peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(val);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */