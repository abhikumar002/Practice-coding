public class LRUCache {

    int capacity;
    Dictionary<int, LinkedListNode<CacheItem>> dic;
    private readonly LinkedList<CacheItem> cacheList;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        dic = new Dictionary<int, LinkedListNode<CacheItem>>(this.capacity);
        cacheList = new LinkedList<CacheItem>();
    }
    
    public int Get(int key) {
        if (dic.TryGetValue(key, out var node))
        {
            cacheList.Remove(node);
            cacheList.AddFirst(node);
            return node.Value.Value;
        }     
        return -1;
    }
    
    public void Put(int key, int value) {
        if (dic.TryGetValue(key, out var node))
        {
            node.Value.Value = value;
            cacheList.Remove(node);
            cacheList.AddFirst(node);
        }
        else
        {
            if (dic.Count >= capacity)
            {
                var lastNode = cacheList.Last;
                dic.Remove(lastNode.Value.Key);
                cacheList.RemoveLast();
            }

            var newNode = new LinkedListNode<CacheItem>(new CacheItem(key, value));
            dic.Add(key, newNode);
            cacheList.AddFirst(newNode);
        }

    }

    private class CacheItem
    {
        public int Key { get; }
        public int Value { get; set; }

        public CacheItem(int key, int value)
        {
            Key = key;
            Value = value;
        }
    }
}
