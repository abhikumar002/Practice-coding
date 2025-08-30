public class LRUCache {
    
    private Dictionary<int,LinkedListNode<(int key, int value)>> dic;
    private LinkedList<(int key, int value)> deque;
    private int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        dic = new Dictionary<int,LinkedListNode<(int key, int value)>>(capacity);
        deque = new LinkedList<(int key, int value)>();
    }
    
    public int Get(int key) {
        if(dic.ContainsKey(key)){
            var node = dic[key];
            deque.Remove(node);
            deque.AddFirst(node);
            return node.Value.value;
        }
        return -1;
    }
    
    public void Put(int key, int value) {
        if(dic.ContainsKey(key)){
            var node = dic[key];
            node.Value = (key, value);
            deque.Remove(node);
            deque.AddFirst(node);
        }
        else{
            if(deque.Count >= capacity) {
                var lastNode = deque.Last;
                dic.Remove(lastNode.Value.key);
                deque.RemoveLast();
            }

            var newNode = new LinkedListNode<(int key, int value)>((key, value));
            deque.AddFirst(newNode);   
            dic[key] = newNode;
        }
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */